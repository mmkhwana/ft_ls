#include "../ft_ls.h"

void		ft_perminfo(struct stat d_stat, t_flags flags)
{
	struct passwd		*d_pas;
	struct group		*d_grp;

	ft_putnbr((int)d_stat.st_nlink);
	ft_putchar(' ');
	if (flags.g == 0)
	{
		d_pas = getpwuid(d_stat.st_uid);
		ft_putstr(d_pas->pw_name);
		ft_putchar(' ');
	}
	d_grp = getgrgid(d_stat.st_gid);
	ft_putstr(d_grp->gr_name);
	ft_putchar(' ');
	ft_putnbr((long long)d_stat.st_size);
	ft_putchar(' ');

}