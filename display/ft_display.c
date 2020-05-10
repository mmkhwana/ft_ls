#include "../ft_ls.h"

void            ft_display(t_files *tmp, t_flags flag)
{
    if (!flag.a)
    {
        if (tmp->name[0] != '.')
        {
            if (flag.l == 1)
            {
                ft_printperm(tmp->d_stat);
                ft_perminfo(tmp->d_stat, flag);
                ft_timeperm(tmp->d_stat,flag);
            }
        }
    }
    else
    {
        if (flag.l == 1)
        {
            ft_printperm(tmp->d_stat);
            ft_perminfo(tmp->d_stat, flag);
            ft_timeperm(tmp->d_stat,flag);
        }
    }
    
}