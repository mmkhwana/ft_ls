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
#include <errno.h>
#include <grp.h>
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
	int		rr;
	int		RR;
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
typedef struct 		s_dir
{
	DIR 			*dire;
	t_files			*files;
	struct dirent	*diropt;
}					t_dir;

typedef struct		s_lists
{
	t_files			*files;
	t_files			*temp;
	t_files			*tempSec;
}					t_lists;

typedef struct		s_begin
{
	int				begin;
	int				selected;
}					t_begin;

typedef struct		s_option
{
	struct stat		fstat;
	t_files			*alist;
	char			*newpath;
}					t_option;

typedef struct		s_main
{
	t_flags			flags;
	int				start;
	char			*pwd;
}					t_main;

void		ft_permission(struct stat d_stat);
void		ft_perminfo(struct stat d_stat, t_flags flags);
void        ft_diffperm(struct stat d_stat);
void        ft_printperm(struct stat d_stat);
void        ft_memberperm(struct stat d_stat);
void		ft_timeperm(struct  stat d_stat, t_flags flags);
void        ft_display(t_files *tmp, t_flags flag);
char        *ft_makepath(char *dir, char *file);
void        ft_sort_time_insert(t_files *current, t_files *new_node);
void        ft_sort_time_inserted(t_files **head, t_files *new_node);
t_files     *ft_newlist(struct  dirent *dptr, char *path, t_flags flags);
void        ft_fill_list(struct stat opt, t_files *list);
void        ft_list(t_files **b, struct dirent *dir, char *path, t_flags flags);
void        ft_filllist(struct stat opt, t_files *list);
t_files     *ft_newlist(struct dirent *dir, char * path, t_flags flags);
t_files     *ft_reverse(t_files *head);
void        ft_directory(t_files *temp, char *dir, t_flags flags);
void        *ft_check(char *name);
void        ft_linkpath(t_files *file, char *path, t_flags flags);
t_files     *ft_arange(char *dir, t_flags flags);
t_lists    	ft_arange_fist(char *dir, t_flags flags);
void        ft_arange_sec(t_files *files, char *dir, t_flags flags);
t_files     *ft_config_arange(char *dir, t_flags flags);
void        ft_orderedinsert(t_files **head, t_files *newnode);
void        ft_insertionorder(t_files **heah, t_flags flags);
void        *ft_sectionsetup(char *dir, t_flags flags, t_dir *var);
void        ft_displaysection(int section, t_flags flags);
void        ft_section(char *dir, t_flags flags);
void        ft_timesorted(t_files * curr, t_files *newnode);
void        ft_timeaccessed(t_files **head, t_files *newnode);
void        ft_defineflags(t_flags *flag);
void        ft_flagfault(char x, char *str, int i);
void        ft_flagparam(char *flags, t_flags *flg,int i);
void        ft_flagtype(char *flags, t_flags *flg);
t_begin     ft_flag(char **av, t_flags *flags);
void    	ft_freelist(t_files *files);
void        ft_freelistprv(t_files *files);
void        ft_free(t_files *files);
t_files     *ft_node(t_files *head, t_files *a);
void        ft_getswap(t_files **head, t_files **a, t_files **b);
t_files 	*ft_listOptions(char *path, char *name, t_flags flags);
void        ft_optionsA(t_files *temp, char *pwd, t_flags flags);
void        ft_optionB(t_files *temp, char *pwd, t_flags flags);
t_files     *ft_optionsSetup(char **av, t_files *file, t_main main);
void        ft_option(char **av, t_main main);

#endif
