#include "../ft_ls.h"

void            ft_sort_time_inserted(t_files **head, t_files *new_node)
{
    t_files         *current;

    if (*head == NULL || (*head)->mtime - new_node->mtime < 0)
    {
        new_node->next = *head;
        *head =  new_node;
    }
    else
    {
        current = *head;
        while (current->next != NULL
                && current->next->mtime -  new_node->mtime > 0)
                current = current->next;
        if (current->next !=NULL
            && current->next->mtime - new_node->mtime == 0)
            ft_sort_time_insert(current,new_node);
        else
        {
            new_node->next = current->next;
            new_node->prev = current->prev;
            current->next = new_node;
        }
    }
}