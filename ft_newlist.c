#include "ft_ls.h"

t_files         *ft_newlist(struct  dirent *dptr, char *path, t_flags flags)
{
    t_files         *list;
    struct stat     opt;
    char            *new_path;

    list = NULL;
    new_path = ft_makepath(path, dptr->d_name);
    if (lstat(new_path, &opt) < 0)
        return (NULL);
    free(new_path);
    if (!(list = (t_files *)malloc(sizeof(t_files))))
        return(NULL);
    ft_fill_list(opt, list);
    list->dir = dptr;
    list->name = ft_strdup(dptr->d_name);
    if (S_ISLNK((list)->st_mode))
       ft_link_path(list, new_path, flags);
    return(list);
}