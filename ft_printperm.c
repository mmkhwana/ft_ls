#include    "ft_ls.h"

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

void        ft_memberperm(struct stat d_stat)
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

void        ft_printperm(struct stat d_stat)
{
    ft_permission(d_stat);
    ft_memberperm(d_stat);
    ft_diffperm(d_stat);
}