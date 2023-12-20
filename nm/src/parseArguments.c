#include "../include/ft_nm.h"

int     hasOptionFormat(char *str) {
    if (str != NULL && str[0] == '-' && str[1] != '\0')
        return (1);
    return (0);
}

void    unknownOption(t_var *var, char unknown) {
    write(2, "ft_nm: invalid option -- '", 27);
    write(2, &unknown, 1);
    write(2, "'\nUsage: ft_nm [option(s)] [file(s)]\n List symbols in [file(s)] (a.out by default).\n", 85);
    write(2, "The options are:\n -a,      Display debugger-only symbols\n -g,      Display only external symbols\n -u,      Display only external symbols\n -r,      Reverse the sense of the sort\n -p,      Do not sort the symbols\n", 212);
    freeAll(var);
    exit(1);
}

void    checkAndAddOption(t_var *var, char *new) {
    int j = 0;

    for (int i = 1; new[i] != '\0'; i++) {
        if (new[i] != 'a' && new[i] != 'g' && new[i] != 'u' && new[i] != 'r' && new[i] != 'p')
            unknownOption(var, new[i]);
        else {
            j = 0;
            while (var->options[j] != '\0' && var->options[j] != new[i])
                j++;
            if (var->options[j] == '\0')
                var->options[j] = new[i];
        }
    }
}

void    parseArguments(t_var *var, int ac, char **av) {
    int fileCount = 0;

    for (int i = 1; i < ac; i++) {
        if (hasOptionFormat(av[i]))
            checkAndAddOption(var, av[i]);
        else
            fileCount++;
    }
    if (fileCount == 0)
        var->files = malloc(sizeof(char *) * 2);
    else
        var->files = malloc(sizeof(char *) * (fileCount + 1));
    if (var->files == NULL)
        fatalError(var, "ft_nm: Malloc Error\n");
    if (fileCount == 0) {
        var->files[0] = ft_strdup("a.out");
        if (var->files[0] == NULL)
            fatalError(var, "ft_nm: Malloc Error\n");
        var->files[1] = NULL;
    }
    else {
        fileCount = 0;
        for (int i = 1; i < ac; i++) {
            if (!hasOptionFormat(av[i])) {
                var->files[fileCount] = ft_strdup(av[i]);
                if (var->files[fileCount] == NULL)
                    fatalError(var, "ft_nm: Malloc Error\n");
                fileCount++;
            }
        }
        var->files[fileCount] = NULL;
    }
}