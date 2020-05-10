#include "../ft_ls.h"

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
