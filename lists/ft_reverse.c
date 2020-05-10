#include "../ft_ls.h"

t_files         *ft_reverse(t_files *head)
{
    t_files     *current;
    t_files     *previous;
    t_files     *next;

    current = head;
    previous = NULL;
    while (current)
    {
        next = current->next;
        current->next = previous;
        previous = current;
        current = next;
    }
    head = previous;
    return(head);
}