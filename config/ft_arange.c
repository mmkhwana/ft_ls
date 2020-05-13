#include "../ft_ls.h"

t_files         *ft_arange(char *dir, t_flags flags)
{
    t_lists     list;
    t_files     *temp;

    if (flags.l == 2)
    {
        ft_section(dir, flags);
    }
    list = ft_arange_fist(dir, flags);
    if (!list.files)
    {
        return (NULL);
    }
    temp = list.temp;
    while (temp->next)
    {
        ft_display(temp, flags);
        temp = temp->next;
    }

    ft_display(temp, flags);
    if (flags.RR == 1)
    {
        ft_arange_sec(temp, dir, flags);
    }
    return(list.files);
}