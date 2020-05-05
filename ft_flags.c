#include "ft_ls.h"

void        ft_defineflags(t_flags *flag)
{
    flag->a = 0;
    flag->f = 0;
    flag->g = 0;
    flag->l = 0;
    flag->lg_r = 0;
    flag->sm_r = 0;
    flag->t = 0;
    flag->u = 0;
}

void        ft_flagfault(char x, char *str, int i)
{
    if (i == 1)
    {
        ft_putstr("ls: illegal option --");
        ft_putchar(x);
        ft_putchar(10);
        ft_putstr("usage: ls [-Ralrtfgu] [file ...]");
        ft_putchar(10);
        ft_putendl("fail");
        exit(1);
    }
    else
    {
        ft_putstr("ls:");
        ft_putstr(str);
        ft_putstr(": No such files or directory");
        ft_putchar(10);
    }
}

void        ft_flagparam(char *flags, t_flags *flg,int i)
{
    if (flags[i] == 'a')
    {
        flg->a = 1;
    }
    else if (flags[i] == 'f')
    {
        flg->f = 1;
    }
    else if (flags[i] == 'l')
    {
        flg->l = 1;
    }
    else if (flags[i] == 'R')
    {
        flg->lg_r = 1;
    }
    else if (flags[i] == 'r')
    {
        flg->sm_r = 1;
    }
    else if (flags[i] == 't')
    {
        flg->t = 1;
    }
    else if (flags[i] == 'u')
    {
        flg->u = 1;
    }
    else
    {
        ft_flagfault(flags[i], "nothing", 1)
    }
}

void            ft_flagtype(char *flags, t_flags flg)
{
    int         i;

    i = 1;
    while (flags[i] != '\0')
    {
        ft_flagparam(flags, flg, i);
        i++;
    }
}

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
            ft_flagtype(av[i], flg);
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
