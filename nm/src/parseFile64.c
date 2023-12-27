#include "../include/ft_nm.h"

char    getSymbolType(Elf64_Sym sym, Elf64_Shdr *shdr, Elf64_Ehdr *elf_header) {
    {
  char c = '?';
  uint64_t flags;
  uint64_t bind = ELF64_ST_BIND(sym.st_info);
  uint64_t type = ELF64_ST_TYPE(sym.st_info);
  uint16_t shndx = sym.st_shndx;
  uint64_t shnum = elf_header->e_shnum;

  if (bind == STB_GNU_UNIQUE)
    c = 'u';
  else if(type == STT_GNU_IFUNC)        // indirect GNU function
    c = 'i';
  else if (bind == STB_WEAK)            // weak = like global, but a global of the same name can override a weak
  {
    if(type == STT_OBJECT)              // weak object (variable for instance)
      c = (shndx == SHN_UNDEF) ? 'v' : 'V';
    else                                // weak symbol not specifically associated to a weak object
      c = (shndx == SHN_UNDEF) ? 'w' : 'W';
  }
  else if (sym.st_shndx == SHN_UNDEF)    // undefined symbol
    c = 'U';
  else if (sym.st_shndx == SHN_ABS)     // absolute value, will not be modified at linking
    c = 'A';
  else if (sym.st_shndx == SHN_COMMON)
    c = 'C';
  else if (shndx < shnum) {
    type = shdr[shndx].sh_type;
    flags = shdr[shndx].sh_flags;

    if (type == SHT_NOBITS)             // symbol in uninitialized data section (.bss)
      c = 'B';
    else if (!(flags & SHF_WRITE))
    {
      if(flags & SHF_ALLOC && flags & SHF_EXECINSTR)
        c = 'T';                        // symbol in text (code) section (.text)
      else
        c = 'R';                        // symbol in a read only data section
    }
    else if(flags & SHF_EXECINSTR)
      c = 'T';                          // symbol in text (code) section (.text)
    else
      c = 'D';                          // symbol in initialized data section (.data)
  }
  if (bind == STB_LOCAL && c <= 'Z' && c != '?')
    c += 32;                            // lowercase if symbol is local
  return c;
}
}

void    fillArray(size_t symbolCount, Elf64_Sym *symbolTable, t_sym *symArray, char *strtab, Elf64_Shdr *section_header, Elf64_Ehdr *elf_header) {
    for (size_t i = 0; i < symbolCount; i++) {
        symArray[i].ulValue = (unsigned long)symbolTable[i].st_value;
        hexaUltoa(symArray[i].ulValue, symArray[i].hexValue);
        symArray[i].type = getSymbolType(symbolTable[i], section_header, elf_header);
        ft_strlcpy(symArray[i].name, strtab + symbolTable[i].st_name, 512);
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

            fillArray(symbolCount, symbolTable, symArray, strtab, section_headers, elf_header);
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