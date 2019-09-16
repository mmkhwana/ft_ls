/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_permission.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmkhwana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 15:15:57 by mmkhwana          #+#    #+#             */
/*   Updated: 2019/09/16 16:25:35 by mmkhwana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		ft_dirperm(struct stat d_stat)
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
