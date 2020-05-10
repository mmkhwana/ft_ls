#include "../ft_ls.h"

void        ft_orderedinsert(t_files **head, t_files *newnode)
{
    t_files     *curr;

    if (*head == NULL || ft_strcmp((*head)->name, newnode->name) > 0)
    {
        newnode->next = *head;
        *head = newnode;
    }
    else
    {
        curr = *head;
        while (curr->next != NULL
                && ft_strcmp(curr->next->name, newnode->name) < 0)
        {
            curr = curr->next;
        }
        newnode->next = curr->next;
        newnode->prev = curr->prev;
        curr->next = newnode;
    }
}