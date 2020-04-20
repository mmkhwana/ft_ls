#include "ft_ls.h"

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

void		ft_timeperm(struct stat d_stat, t_flags flag)
{
	int					i;
	size_t				size;
	char				date_time[100];

	size = sizeof(date_time);
	ft_bzero(date_time, size);
	if (flag.u == 1)
		ft_strncpy(date_time, ctime(&d_stat.st_atime), size);
	else
		ft_strncpy(date_time, ctime(&d_stat.st_mtime), size);
	i = 0;
	while (date_time[i] != '\0')
	{
		if (date_time[i] == '\n')
			date_time[i] = '\0';
		i++;
	}
	ft_putstr(date_time);
	ft_putchar(' ');
}

void            ft_display(t_files *tmp, t_flags flag)
{
    if (!flag.a)
    {
        if (tmp->name[0] != '.')
        {
            if (flag.l == 1)
            {
                ft_printperm(tmp->d_stat);
                ft_perminfo(tmp->d_stat, flag);
                ft_timeperm(tmp->d_stat,flag);
            }
        }
    }
    else
    {
        if (flag.l == 1)
        {
            ft_printperm(tmp->d_stat);
            ft_perminfo(tmp->d_stat, flag);
            ft_timeperm(tmp->d_stat,flag);
        }
    }
    
}