#include "../include/ft_nm.h"

bool    parse64bitFile(t_var *var, char *filePath) {
    Elf64_Ehdr *elf_header = (Elf64_Ehdr *)var->map;

    // Move to the section header table
    Elf64_Shdr *section_headers = (Elf64_Shdr *)(var->map + elf_header->e_shoff);

    // Find the section containing symbol names
    Elf64_Shdr *strtab_header = &section_headers[elf_header->e_shstrndx];
    char *section_names = var->map + strtab_header->sh_offset;

    // Find the section containing symbols
    for (int i = 0; i < elf_header->e_shnum; i++) {
        Elf64_Shdr *section_header = &section_headers[i];

        // Check if the section contains symbols
        if (section_header->sh_type == SHT_SYMTAB) {
            // Read the symbol table
            Elf64_Sym *symbol_table = (Elf64_Sym *)(var->map + section_header->sh_offset);

            // Calculate the number of symbols in the table
            size_t symbol_count = section_header->sh_size / sizeof(Elf64_Sym);

            // Find the symbol string table
            Elf64_Shdr *strtab_section = &section_headers[section_header->sh_link];
            char *strtab = var->map + strtab_section->sh_offset;

            // Print the symbols
            printf("Symbols in section %s:\n", &section_names[section_header->sh_name]);
            for (size_t j = 0; j < symbol_count; j++) {
                // Print the symbol value and name
                printf("%lx %s\n", (unsigned long)symbol_table[j].st_value,
                       strtab + symbol_table[j].st_name);
            }
        }
    }
    (void)filePath;
    return (true);
}




bool parse32bitFile(t_var *var, char *filePath) {
    Elf32_Ehdr *elf_header = (Elf32_Ehdr *)var->map;

    // Move to the section header table
    Elf32_Shdr *section_headers = (Elf32_Shdr *)(var->map + elf_header->e_shoff);

    // Find the section containing symbol names
    Elf32_Shdr *strtab_header = &section_headers[elf_header->e_shstrndx];
    char *section_names = var->map + strtab_header->sh_offset;

    // Find the section containing symbols
    for (int i = 0; i < elf_header->e_shnum; i++) {
        Elf32_Shdr *section_header = &section_headers[i];

        // Check if the section contains symbols
        if (section_header->sh_type == SHT_SYMTAB) {
            // Read the symbol table
            Elf32_Sym *symbol_table = (Elf32_Sym *)(var->map + section_header->sh_offset);

            // Calculate the number of symbols in the table
            size_t symbol_count = section_header->sh_size / sizeof(Elf32_Sym);

            // Find the symbol string table
            Elf32_Shdr *strtab_section = &section_headers[section_header->sh_link];
            char *strtab = var->map + strtab_section->sh_offset;

            // Print the symbols
            printf("Symbols in section %s:\n", &section_names[section_header->sh_name]);
            for (size_t j = 0; j < symbol_count; j++) {
                // Print the symbol value and name
                printf("%x %s\n", symbol_table[j].st_value, strtab + symbol_table[j].st_name);
            }
        }
    }
    (void)filePath;
    return (true);
}