#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// extern int ft_strlen(char *str);
extern char *ft_strcpy(char *dest, const char *src);

int main() {
    char dest[4];
    char *src = "toto";

    ft_strcpy(dest, src);
    printf("%s\n", dest);
    return (0);
}