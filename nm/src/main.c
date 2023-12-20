#include "../include/ft_nm.h"

void    fileError(char *filePath, int type) {
    char *message = strerror(errno);
    write(2, "ft_nm: ", 7);
    if (type == 0) {
        if (ft_strncmp(message, "No such file", 12) == 0) {
            write(2, "'", 1);
            write(2, filePath, ft_strlen(filePath));
            write(2, "': ", 3);
            write(2, "No such file", 12);
        }
        else {
            write(2, filePath, ft_strlen(filePath));
            write(2, ": ", 2);
            write(2, message, ft_strlen(message));
        }
    }
    else if (type == 1) {
        write(2, "Warning: '", 10);
        write(2, filePath, ft_strlen(filePath));
        write(2, "' is a directory", 16);
    }
    else if (type == 2) {
        write(2, "Warning: '", 10);
        write(2, filePath, ft_strlen(filePath));
        write(2, "' is not an ordinary file", 25);
    }
    else if (type == 3) {
        write(2, filePath, ft_strlen(filePath));
        write(2, ": file format not recognized", 28);
    }
    write(2, "\n", 1);
}

bool isValidFile(t_var *var, char *filePath) {
    struct stat file;
    bool isValid = false;

    if (fstat(var->fd, &file) < 0)
        fatalError(var, "ft_nm: fstat Error\n");
    var->fileSize = file.st_size;
    if (S_ISDIR(file.st_mode))
        fileError(filePath, 1);
    else if (!S_ISREG(file.st_mode)) 
        fileError(filePath, 2);
    else if (var->fileSize > 0)
        isValid = true;
    return (isValid);
}

bool    parseMap(t_var *var, char *filePath) {
    bool fileOK = false;

    if (var->map[0] == ELFMAG0 && var->map[1] == ELFMAG1
        && var->map[2] == ELFMAG2 && var->map[3] == ELFMAG3) {
        fileOK = true; // to be continued
    }
    else
        fileError(filePath, 3);
    return (fileOK);
}

bool    mapFile(t_var *var, char *filePath) {
    bool parsingOK = false;

    var->map = (char *)mmap(NULL, var->fileSize, PROT_READ, MAP_PRIVATE, var->fd, 0);
    if (var->map == MAP_FAILED)
        fatalError(var, "ft_nm: mmap Error\n");
    parsingOK = parseMap(var, filePath);
    if (munmap(var->map, var->fileSize) < 0)
        fatalError(var, "ft_nm: munmap Error\n");
    return (parsingOK);
}

void    handleFile(t_var *var, char *filePath) {
    bool fileTypeOK = false;
    bool parsingOK = false;
    
    var->fd = open(filePath, O_RDONLY);
    if (var->fd < 0) {
        fileError(filePath, 0);
    }
    else
        fileTypeOK = isValidFile(var, filePath);
    if (fileTypeOK)
        parsingOK = mapFile(var, filePath);
    if (!fileTypeOK || !parsingOK)
        var->ret = 1;
    if (var->fd != -1 && close(var->fd) < 0)
        fatalError(var, "ft_nm: Close Error\n");
    var->fd = -1;
}

int main(int ac, char **av) {
    t_var var;
    
    ft_bzero(var.options, 6);
    var.files = NULL;
    var.map = NULL;
    var.ret = 0;
    var.fd = -1;
    var.fileSize = 0;
    parseArguments(&var, ac, av);
    // printf("Options are : %s\n\n", var.options);    //debug
    for (int i = 0; var.files[i] != NULL; i++) {
        // printf("File number %d is : %s\n", i, var.files[i]);    //debug
        handleFile(&var, var.files[i]);
    }
    freeAll(&var);
    return (var.ret);
} 