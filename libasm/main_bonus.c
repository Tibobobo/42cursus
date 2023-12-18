#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>

typedef struct s_list
{
    void *data;
    struct s_list *next;
}   t_list;

extern int	ft_list_size(t_list *begin_list);


int main() {
    int data = 42;

    t_list first;
    t_list second;
    t_list third;
    first.data = &data;
    second.data = &data;
    third.data = &data;
    first.next = &second;
    second.next = &third;
    third.next = NULL;

    printf("List size : %d\n", ft_list_size(&first));
    
    return (0);
}
