
#include "ft_ls.h"

void        ft_memeberperm(struct stat d_stat)
{
    if (d_stat.st_mode & S_IRGRP)
		ft_putchar('r');
	else
		ft_putchar('-');
	if (d_stat.st_mode & S_IWGRP)
		ft_putchar('w');
	else
		ft_putchar('-');
	if (d_stat.st_mode & S_IXGRP)
		ft_putchar('x');
	else
		ft_putchar('-');
}