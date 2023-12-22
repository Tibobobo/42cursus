#ifndef FT_NM_H

# define FT_NM_H

# include <elf.h>
# include <fcntl.h>
# include <unistd.h>
# include <sys/mman.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <errno.h>
# include <stdbool.h>
# include "../libft/libft.h"

typedef struct s_var
{
	char			options[6];
	char            **files;
    char            *map;
    int             fd;
    int             ret;
    size_t          fileSize;
}			t_var;

typedef struct s_sym
{
    char            value[17];
    char            type;
    char            name[512];
}           t_sym;

void                parseArguments(t_var *var, int ac, char **av);
void                freeAll(t_var *var);
void                fatalError(t_var *var, char *errorMessage);
void                handleFile(t_var *var, char *filePath);
bool                parse32bitFile(t_var *var, char *filePath);
bool                parse64bitFile(t_var *var, char *filePath);
void                fileError(char *filePath, int type);
void                hexaUltoa(unsigned long value, char *dest);
int                 compareSymNames(const char *first, const char *second);

#endif