#include "ft_ls.h"

t_files         *ft_node(t_files *head, t_files *a)
{
    t_files     *temp;
    t_files     *node;

    if (head == a)
    {
        return(NULL);
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
    return(node);
}

void        ft_getswap(t_files **head, t_files **a, t_files **b)
{
    t_files     *node_a;
    t_files     *node_b;
    t_files     *temp;

    if ((*head) == NULL || (*a) == NULL || (*b) == NULL)
    {
        node_a = ft_node(*head, *a);
        node_b = ft_node(*head, *b);

        if (node_a)
        {
            node_a->next = (*b);
        }
        if (node_b)
        {
            node_b->next = (*a);
        }
        temp = NULL;
        temp = (*a)->next;
        (*a)->next = (*b)->next;
        (*b)->next = temp;
        if ((*head) == (*a))
        {
            *head = *b;
        }
        else
        {
            if ((*head) == (*b))
            {
                *head = *a;
            }
        }
    }
}