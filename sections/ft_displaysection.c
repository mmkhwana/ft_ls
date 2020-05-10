#include "../ft_ls.h"

void        ft_displaysection(int section, t_flags flags)
{
    if (flags.l == 1)
    {
        ft_putstr("total ");
        ft_putnbr(section);
        ft_putchar('\n');
    }
}