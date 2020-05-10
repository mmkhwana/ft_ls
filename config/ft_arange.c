#include "../ft_ls.h"

t_files         *ft_arrange(char *dir, t_flags flags)
{
    t_lists     list;
    t_files     *temp;

    if (flags.l == 1)
    {
        ft_section(dir, flags);
    }
    list = ft_arange_fist(dir, flags);
    if (!list.files)
    {
        return (NULL);
    }
    temp = list.temp;
    while (list.temp->next)
    {
        ft_display(list.temp, flags);
        list.temp = list.temp->next;
    }

    ft_display(list.temp, flags);
    if (flags.RR == 1)
    {
        ft_arange_sec(list.temp, dir, flags);
    }
    return(list.files);
}