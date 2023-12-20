#include "../include/ft_nm.h"

int main(int ac, char **av) {
    t_var var;
    
    ft_bzero(var.options, 6);
    var.files = NULL;
    var.map = NULL;
    parseArguments(&var, ac, av);
    printf("Options are : %s\n\n", var.options);
    for (int i = 0; var.files[i] != NULL; i++)
        printf("File number %d is : %s\n", i, var.files[i]);
    freeAll(&var);
    return (0);
} 