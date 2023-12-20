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
# include "../libft/libft.h"

typedef struct s_var
{
	char			options[6];
	char            **files;
    void            *map;
}			t_var;

void    parseArguments(t_var *var, int ac, char **av);
void    freeAll(t_var *var);
void    fatalError(t_var *var, char *errorMessage);

#endif