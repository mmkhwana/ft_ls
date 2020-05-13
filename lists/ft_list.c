#include "../ft_ls.h"

void        ft_list(t_files **b, struct dirent *dir, char *path, t_flags flags)
{
    t_files     *list;

    list = *b;
    if (!list)
    {
        list = ft_newlist(dir, path, flags);
    }
    else
    {
        while ((list)->next)
        {
            list = list->next;
        }
        list->next = ft_newlist(dir, path, flags);
        list->next->prev = list;    
    }
}