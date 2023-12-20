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
    if (var->map != NULL && var->map != MAP_FAILED) {
        munmap(var->map, var->fileSize);
        var->map = NULL;
        var->fileSize = 0;
    }
}

void    fatalError(t_var *var, char *errorMessage) {
     write(2, errorMessage, ft_strlen(errorMessage));
     freeAll(var);
     exit(1);
}