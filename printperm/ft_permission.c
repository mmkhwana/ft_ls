#include "../ft_ls.h"

void		ft_permission(struct stat d_stat)
{
	if (S_ISDIR(d_stat.st_mode))
		ft_putchar('d');
	else
		ft_putchar('-');
	if (d_stat.st_mode & S_IRUSR)
		ft_putchar('r');
	else
		ft_putchar('-');
	if (d_stat.st_mode & S_IWUSR)
		ft_putchar('w');
	else
		ft_putchar('-');
	if (d_stat.st_mode & S_IXUSR)
		ft_putchar('x');
	else
		ft_putchar('-');
}