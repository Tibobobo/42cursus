#include "../include/ft_nm.h"

char    getSymbolType(Elf64_Sym sym, Elf64_Shdr *shdr) {
    char  c;

    if (ELF64_ST_BIND(sym.st_info) == STB_GNU_UNIQUE)
        c = 'u';
    else if (ELF64_ST_BIND(sym.st_info) == STB_WEAK)
    {
        c = 'W';
        if (sym.st_shndx == SHN_UNDEF)
            c = 'w';
    }
    else if (ELF64_ST_BIND(sym.st_info) == STB_WEAK && ELF64_ST_TYPE(sym.st_info) == STT_OBJECT)
    {
        c = 'V';
        if (sym.st_shndx == SHN_UNDEF)
            c = 'v';
    }
    // else if (ELF64_ST_TYPE(sym.st_info) == STT_NOTYPE && sym.st_shndx != SHN_UNDEF)
    //     c = 'N';
    // else if (ELF64_ST_TYPE(sym.st_info) == STT_SECTION && sym.st_shndx == SHN_UNDEF)
    //     c = 'r';
    // else if (ELF64_ST_TYPE(sym.st_info) == STT_TLS)
    //     c = 't';
    else if (sym.st_shndx == SHN_UNDEF)
        c = 'U';
    else if (sym.st_shndx == SHN_ABS)
        c = 'A';
    else if (sym.st_shndx == SHN_COMMON)
        c = 'C';
    else if (shdr[sym.st_shndx].sh_type == SHT_NOBITS
        && shdr[sym.st_shndx].sh_flags == (SHF_ALLOC | SHF_WRITE))
        c = 'B';
    else if (shdr[sym.st_shndx].sh_type == SHT_PROGBITS
        && shdr[sym.st_shndx].sh_flags == SHF_ALLOC)
        c = 'R';
    else if (shdr[sym.st_shndx].sh_type == SHT_PROGBITS
        && shdr[sym.st_shndx].sh_flags == (SHF_ALLOC | SHF_WRITE))
        c = 'D';
    else if (shdr[sym.st_shndx].sh_type == SHT_PROGBITS
        && shdr[sym.st_shndx].sh_flags == (SHF_ALLOC | SHF_EXECINSTR))
        c = 'T';
    else if (shdr[sym.st_shndx].sh_type == SHT_DYNAMIC)
        c = 'D';
    else
        c = '?';
    if (ELF64_ST_BIND(sym.st_info) == STB_LOCAL && c != '?')
        c += 32;
    return c;
}

void    sortArray(size_t symbolCount, t_sym *symArray, char *options) {
    t_sym tmp;
    size_t i = 0;
    size_t j = 0;

    if (!ft_strchr(options, 'r')) {
        while (i < symbolCount - 1) {
            j = i + 1;
            while (j < symbolCount) {
                if (compareSymNames(symArray[i].name, symArray[j].name) > 0) {
                    tmp = symArray[i];
                    symArray[i] = symArray[j];
                    symArray[j] = tmp;
                }
                j++;
            }
            i++;
        }
    }
    else {
        while (i < symbolCount - 1) {
            j = i + 1;
            while (j < symbolCount) {
                if (compareSymNames(symArray[i].name, symArray[j].name) < 0) {
                    tmp = symArray[i];
                    symArray[i] = symArray[j];
                    symArray[j] = tmp;
                }
                j++;
            }
            i++;
        }
    }
}

void    fillArray(size_t symbolCount, Elf64_Sym *symbolTable, t_sym *symArray, char *strtab, Elf64_Shdr *section_header) {
    for (size_t i = 0; i < symbolCount; i++) {
        hexaUltoa((unsigned long)symbolTable[i].st_value, symArray[i].value);
        symArray[i].type = getSymbolType(symbolTable[i], section_header);
        ft_strlcpy(symArray[i].name, strtab + symbolTable[i].st_name, 512);
    }
}

char *setTypesToPrint(char *options) {
    if (ft_strchr(options, 'u'))
        return ("Uw");
    else if (ft_strchr(options, 'g'))
        return ("UwWACBRDT");
    else if (ft_strchr(options, 'a'))
        return ("UWACBRDTNuwactrbd");
    else
        return ("UWACBRDTurtwcbd");
}

void    printOutput(size_t symbolCount, t_sym *symArray, char *options) {
    char *toPrint = setTypesToPrint(options);
    for (size_t i = 0; i < symbolCount; i++) {
        if (!(symArray[i].name[0] == '\0' && symArray[i].type != 'a')
            && ft_strchr(toPrint, symArray[i].type)) {
            (symArray[i].type == 'U' || symArray[i].type == 'w') ?
            write(1, "                ", 16) : write(1, symArray[i].value, 16);
            write(1, " ", 1);
            write(1, &symArray[i].type, 1);
            write(1, " ", 1);
            write(1, symArray[i].name, ft_strlen(symArray[i].name));
            write(1, "\n", 1);
        }
    }
}

bool    parse64bitFile(t_var *var, char *filePath) {
    Elf64_Ehdr *elf_header = (Elf64_Ehdr *)var->map;
    if ((size_t)elf_header->e_shoff > var->fileSize)
        return (fileError(filePath, 5), false);
    Elf64_Shdr *section_headers = (Elf64_Shdr *)(var->map + elf_header->e_shoff);
    size_t symbolCount = 0;

    if (var->files[0] != NULL && var->files[1] != NULL) {
        write(1, "\n", 1);
        write(1, filePath, ft_strlen(filePath));
        write(1, ":\n", 2);
    }
    for (int i = 0; i < elf_header->e_shnum; i++) {
        Elf64_Shdr *section_header = &section_headers[i];

        if (section_header->sh_type == SHT_SYMTAB) {
            if ((size_t)section_header->sh_offset > var->fileSize)
                return (fileError(filePath, 5), false);
            Elf64_Sym *symbolTable = (Elf64_Sym *)(var->map + section_header->sh_offset);
            symbolCount = section_header->sh_size / sizeof(Elf64_Sym);
            t_sym *symArray = malloc(sizeof(t_sym) * (symbolCount));
            if (symArray == NULL)
                fatalError(var, "ft_nm: Malloc Error\n");
    
            Elf64_Shdr *strtab_section = &section_headers[section_header->sh_link];
            if ((size_t)strtab_section->sh_offset > var->fileSize)
                return (fileError(filePath, 5), false);
            char *strtab = var->map + strtab_section->sh_offset;

            fillArray(symbolCount, symbolTable, symArray, strtab, section_headers);
            if (!ft_strchr(var->options, 'p'))
                sortArray(symbolCount, symArray, var->options);
            printOutput(symbolCount, symArray, var->options);
            free(symArray);
        }
    }
    if (symbolCount == 0)
        fileError(filePath, 6);
    return (true);
}