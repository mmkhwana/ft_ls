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

typedef struct		s_files
{
	char			*name;
	char			*link;
	struct s_files	*next;
	struct s_files	*prev;
	struct s_files	*sub_dir;
	struct dirent	*dir;
	struct stat		d_stat;
	time_t			atime;
	mode_t			st_mode;
	nlink_t			st_nlink;
	time_t			mtime;
	uid_t			st_uid;
	gid_t			st_gid;
	off_t			st_size;
	ino_t			st_ino;
	blkcnt_t		st_blocks;
}					t_files;

void		ft_permissions(struct stat d_stat);
void		ft_perminfo(struct stat d_stat, t_flags flags);
void        ft_diffperm(struct stat d_stat);
void        ft_printperm(struct stat d_stat);
void        ft_memberperm(struct stat d_stat);
void		ft_timeperm(struct  stat d_stat, t_flags flags);
void        ft_display(t_files *tmp, t_flags flag);
char        *ft_makepath(char *dir, char *file);
void        ft_sort_time_insert(t_files *current, t_files *new_node);
void        ft_sort_time_insert_b(t_files **head, t_files *new_node);
t_files     *ft_newlist(struct  dirent *dptr, char *path, t_flags flags);
void        ft_fill_list(struct stat opt, t_files *list);
void        ft_list(t_files **b, struct dirent *dir, char path, t_flags flags);

#endif
