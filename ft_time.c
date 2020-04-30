#include "ft_ls.h"

void        ft_timesorted(t_files * curr, t_files *newnode)
{
    if (ft_strcmp(curr->next->name, newnode->name) > 0)
    {
        newnode->next = curr->next;
        curr->next = newnode;
    }
    else
    {
        while (curr->next != NULL
                && ft_strcmp(curr->next->name, newnode->name) < 0
                && curr->next->atime -newnode->atime == 0)
                {
                    curr = curr->next;
                }
        newnode->next = curr->next;
        newnode->prev = curr->prev;
        curr->next = newnode;
    }
}

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
            ft_timeaccessed(current, newnode);
        }
        else
        {
            newnode->next = current->next;
            newnode->prev = current->prev;
            current->next = newnode;
        }
    }   
}