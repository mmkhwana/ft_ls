#include "../ft_ls.h"

void            ft_display(t_files *tmp, t_flags flag)
{    
    if (flag.l == 2 )
    {
        if (!(tmp->name[0] == '.'))
        {
            ft_printperm(tmp->d_stat);
            ft_perminfo(tmp->d_stat, flag);
            ft_timeperm(tmp->d_stat,flag); 
            ft_putendl(tmp->name);
        }
        return ;
    }
    else if (flag.a == 1)
    {
        ft_putendl(tmp->name);
    }
    else if (flag.t == 1)
    {
        ft_putendl(tmp->name);
    }
    else if (flag.rr == 1)
    {
        ft_putendl(tmp->name);
    }
    else if (flag.RR == 1)
    {
        if (!(tmp->name[0] == '.'))
            ft_putendl(tmp->name);
    }
    else
    {
        if (!(tmp->name[0] == '.'))
            ft_putendl(tmp->name);
    }     
}