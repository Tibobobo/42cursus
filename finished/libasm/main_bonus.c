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
extern void	ft_list_push_front(t_list **begin_list, void *data);


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

    t_list *head = &first;
    ft_list_push_front(&head, &data);
    printf("Added a new element first, data : %d\n", *(int *)head->data);
    printf("New list size after push_front: %d\n", ft_list_size(head));

    
    return (0);
}
