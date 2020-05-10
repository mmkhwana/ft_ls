#include "../ft_ls.h"

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