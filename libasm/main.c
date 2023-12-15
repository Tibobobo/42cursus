#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// extern int ft_strlen(char *str);
// extern char *ft_strcpy(char *dest, const char *src);
extern int ft_strcmp(const char *s1, const char *s2);

int main() {
    char *str1 = "4124964";
    char *str2 = "4124";

    printf("%d\n", ft_strcmp(str1, str2));
    printf("%d\n", strcmp(str1, str2));
    return (0);
}