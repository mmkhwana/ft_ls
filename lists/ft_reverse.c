#include "../ft_ls.h"

t_files         *ft_reverse(t_files *head)
{
    t_files     *current;
    t_files     *previous;
    t_files     *next;

    curr = head;
    previous = NULL;
    while (curr)
    {
        next = current->next;
        current->next = previous;
        previous = current;
        current = next;
    }
    head = previous;
    return(head);
}