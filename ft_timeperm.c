/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_timeperm.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmkhwana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 16:50:35 by mmkhwana          #+#    #+#             */
/*   Updated: 2019/09/16 17:59:18 by mmkhwana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		ft_timeperm(struct stat d_stat, t_flags flag)
{
	int					i;
	size_t				size;
	char				date_time[100];

	size = sizeof(date_time);
	ft_bzero(date_time, size);
	if (flags.u == 1)
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