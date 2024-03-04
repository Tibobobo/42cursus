#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>

extern size_t ft_strlen(char *str);
extern char *ft_strcpy(char *dest, const char *src);
extern int ft_strcmp(const char *s1, const char *s2);
extern size_t ft_write(int fd, const void *buf, size_t count);
extern size_t ft_read(int fd, const void *buf, size_t count);
extern char *ft_strdup(const char *s);

int main() {

    char *s1 = "Hello world";
    char *s2 = "Salut ca va ?";
    char *empty = "";

    //ft_strlen

    printf("strlen(s1) = %ld\n", strlen(s1));
    printf("strlen(s2) = %ld\n", strlen(s2));
    printf("strlen(empty) = %ld\n", strlen(empty));

    printf("ft_strlen(s1) = %ld\n", ft_strlen(s1));
    printf("ft_strlen(s2) = %ld\n", ft_strlen(s2));
    printf("ft_strlen(empty) = %ld\n", ft_strlen(empty));

    char buffer[16];

    //ft_strcpy

    printf("strcpy(s1, buffer) = %s\n", strcpy(buffer, s1));
    printf("buffer = %s\n", buffer);
    
    char buffer2[16];

    printf("strcpy(s1, buffer2) = %s\n", ft_strcpy(buffer2, s1));
    printf("buffer2 = %s\n", buffer2);

    //ft_strcmp

    char *s3 = "Hello";

    printf("strcmp(s1, s2) = %d\n", strcmp(s1, s2));
    printf("strcmp(s1, empty) = %d\n", strcmp(s1, empty));
    printf("strcmp(s1, buffer2) = %d\n", strcmp(s1, buffer2));
    printf("strcmp(s1, s3) = %d\n", strcmp(s1, s3));

    printf("ft_strcmp(s1, s2) = %d\n", ft_strcmp(s1, s2));
    printf("ft_strcmp(s1, empty) = %d\n", ft_strcmp(s1, empty));
    printf("ft_strcmp(s1, buffer) = %d\n", ft_strcmp(s1, buffer));
    printf("ft_strcmp(s1, s3) = %d\n", ft_strcmp(s1, s3));

    //ft_write

    write(1, s1, strlen(s1));
    write(1, "\n", 1);

    ft_write(1, s1, ft_strlen(s1));
    ft_write(1, "\n", 1);

    //ft_read

    int fd = open("./ft_strlen.s", O_RDONLY);
    char buffer3[4096];
    int ret = read(fd, buffer3, 10);
    buffer3[10] = '\0';
    printf("read return value: %d, read bytes: %s\n", ret, buffer);
    close(fd);

    fd = open("./ft_strlen.s", O_RDONLY);
    ret = ft_read(fd, buffer3, 10);
    buffer3[10] = '\0';
    printf("ft_read return value: %d, read bytes: %s\n", ret, buffer);
    close(fd);

    //ft_strdup

    char *cpy = NULL;
    char *cpy2 = NULL;

    cpy = strdup(s1);
    printf("strdup copy : %s\n", cpy);
    free(cpy);

    cpy2 = ft_strdup(s1);
    printf("strdup copy : %s\n", cpy2);
    free(cpy2);

    //errors 

    // write(42, "coucou\n", 7);
    // ft_write(42, "coucou\n", 7);
    // perror("after write, errno = ");

    // fd = open("./doesntexist", O_RDONLY);
    // // ret = read(fd, buffer, 10);
    // ret = ft_read(fd, buffer, 10);
    // perror("after read, errno = ");

    return (0);
}