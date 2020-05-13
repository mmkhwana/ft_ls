#include "../ft_ls.h"

void        ft_flagparam(char *flags, t_flags *flg, int i)
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
        //flg->a = 1;
    }
    else if (flags[i] == 'R')
    {
        flg->RR = 1;
    }
    else if (flags[i] == 'r')
    {
        flg->rr = 1;
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
        ft_flagfault(flags[i], "nothing", 1);
    }
}