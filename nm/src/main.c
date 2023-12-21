#include "../include/ft_nm.h"

int main(int ac, char **av) {
    t_var var;
    
    ft_bzero(var.options, 6);
    var.files = NULL;
    var.map = NULL;
    var.ret = 0;
    var.fd = -1;
    var.fileSize = 0;
    parseArguments(&var, ac, av);
    for (int i = 0; var.files[i] != NULL; i++) {
        handleFile(&var, var.files[i]);
    }
    freeAll(&var);
    return (var.ret);
} 