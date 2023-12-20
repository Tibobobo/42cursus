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
}

void    fatalError(t_var *var, char *errorMessage) {
     write(2, errorMessage, ft_strlen(errorMessage));
     freeAll(var);
     exit(1);
}