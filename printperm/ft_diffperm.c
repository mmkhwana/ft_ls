#include "../ft_ls.h"

void        ft_diffperm(struct stat d_stat)
{
    if (d_stat.st_mode & S_IROTH)
		ft_putchar('r');
	else
		ft_putchar('-');
	if (d_stat.st_mode & S_IWOTH)
		ft_putchar('w');
	else
		ft_putchar('-');
	if (d_stat.st_mode & S_IXOTH)
		ft_putchar('x');
	else
		ft_putchar('-');
	ft_putchar(' ');
}