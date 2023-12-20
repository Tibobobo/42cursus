#include "../include/ft_nm.h"

void    freeArray(char **array) {
    for (int i = 0; array[i] != NULL; i++) {
        free(array[i]);
    }
    free(array);
}

void    freeAll(t_var *var) {
    if (var->files != NULL)
        freeArray(var->files);
    if (var->fd > 0) {
        close(var->fd);
        var->fd = -1;
    }
}

void    fatalError(t_var *var, char *errorMessage) {
     write(2, errorMessage, ft_strlen(errorMessage));
     freeAll(var);
     exit(1);
}