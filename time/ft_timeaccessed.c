#include "../ft_ls.h"

void        ft_timeaccessed(t_files **head, t_files *newnode)
{
    t_files     *current;

    if (*head == NULL || (*head)->atime - newnode->atime < 0)
    {
        newnode->next = *head;
        *head = newnode;
    }
    else
    {
        current = *head;
        while (current->next != NULL
                && current->next->atime - newnode->atime> 0)
        {
            current = current->next;
        }
        if (current->next != NULL && current->next->atime - newnode->atime == 0)
        {
            ft_timeaccessed(&current, newnode);
        }
        else
        {
            newnode->next = current->next;
            newnode->prev = current->prev;
            current->next = newnode;
        }
    }   
}
