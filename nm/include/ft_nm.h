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

enum    e_symTypes
{
    A,B,C,D,G,N,R,S,T,U,V,W,
    b,d,g,i,p,r,s,t,u,v,w,minus,questionMark,
};

typedef struct s_var
{
	char			options[6];
	char            **files;
    char            *map;
    int             fd;
    int             ret;
    size_t          fileSize;
}			t_var;

typedef struct s_sym64
{
    Elf64_Sym       sym;
    char            *name;
    int             type;
}           t_sym64;

typedef struct s_sym32
{
    Elf32_Sym       sym;
    char            *name;
    int             type;
}           t_sym32;

void                parseArguments(t_var *var, int ac, char **av);
void                freeAll(t_var *var);
void                fatalError(t_var *var, char *errorMessage);
void                handleFile(t_var *var, char *filePath);
bool                parse32bitFile(t_var *var, char *filePath);
bool                parse64bitFile(t_var *var, char *filePath);
void                fileError(char *filePath, int type);
// uint16_t	        ft_uint16(uint16_t n, bool littleEndian);
// uint32_t	        ft_uint32(uint32_t n, bool littleEndian);
// uint64_t	        ft_uint64(uint64_t n, bool littleEndian);
// unsigned int	    ft_unsignedInt(unsigned int n, bool littleEndian);
// long unsigned int	ft_longUnsignedInt(long unsigned int n, bool littleEndian);
// int	                ft_int(int n, bool littleEndian);

#endif