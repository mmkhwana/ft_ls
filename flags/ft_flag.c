#include "../ft_ls.h"

t_begin         ft_flag(char **av, t_flags *flags)
{
    int         flg;
    int         x;
    t_begin     begin;

    x = 0;
    begin.selected = 1;
    begin.begin = 1;
    flg = 1;
    while (av[++x] != NULL)
    {
        if (av[x][0] == '-' && flg == 1)
        {
            ft_flagtype(av[x], flags);
        }
        else if (av[x][0] != '-' && flg == 1)
        {
            flg = 0;
            begin.begin = x;
        }
        else if (av[x][0] == '-' && flg == 0)
        {
            ft_flagfault('x', av[x], 2);
        }
        else
        {
            flg = 0;
        }
        if (av[x][0] != '-')
        {
            begin.selected++;
        }
        
    }
    return(begin);
}
