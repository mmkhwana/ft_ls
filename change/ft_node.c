#include "../ft_ls.h"

t_files         *ft_node(t_files *head, t_files *a)
{
    t_files     *temp;
    t_files     *node;

    if (head == a)
    {
        return (NULL);
    }
    temp = head;
    node = NULL;
    while (temp && temp != a)
    {
        node = temp;
        temp = temp->next;
    }
    if (temp != a)
    {
        ft_putendl("error: node not found!");
        ft_putendl("EXIT_FAILURE");
        exit(1);
    }
    return (node);
}
