/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmkhwana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 09:00:39 by mmkhwana          #+#    #+#             */
/*   Updated: 2019/09/16 17:59:23 by mmkhwana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
#define FT_LS_H

#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <pwd.h>
#include <uuid/uuid.h>
#include <grp.h>
#include <uuid/uuid.h>
#include <time.h>
#include "libft/libft.h"


typedef	struct	s_flags
{
	int		l;
	int		a;
	int		t;
	int		g;
	int		u;
	int		f;
}			t_flags;

void		ft_permissions(struct stat d_stat);
void		ft_perminfo(struct stat	d_stat);
void		ft_timeperm(struct  stat d_stat, f_flags flags);

#endif
