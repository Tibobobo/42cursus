#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>

// extern int ft_strlen(char *str);
// extern char *ft_strcpy(char *dest, const char *src);
// extern int ft_strcmp(const char *s1, const char *s2);
// extern size_t ft_write(int fd, const void *buf, size_t count);
// extern size_t ft_read(int fd, const void *buf, size_t count);

extern char *ft_strdup(const char *s);

int main() {

    char *src = "Salut les amis ca va ?";
    char *dest = ft_strdup(src);
    if (dest == NULL)
        perror("PLOP");

    printf("%s\n", dest);
    if (dest != NULL)
        free(dest);


    //  READ

    // int fd = open("./ft_strlen.s", O_RDONLY);
    // char buffer[4096];

    // int ret = ft_read(fd, buffer, 10);
    // buffer[10] = '\0';
    // printf("return value: %d, read bytes: %s\n", ret, buffer);
    // perror("PLOP");
    // close(fd);

    return (0);
}