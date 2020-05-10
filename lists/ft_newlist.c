#include "../ft_ls.h"

t_files         *ft_newlist(struct dirent *dir, char * path, t_flags flags)
{
    t_files     *list;
    struct stat dstat;
    char        *newpath;

    list = NULL;
    newpath = ft_makepath(path, dir->d_name);
    if(lstat(newpath, &dstat) < 0)
        return(NULL);
    free(newpath);
    if(!(list = (t_files *)malloc(sizeof(t_files))))
        return(NULL);
    ft_filllist(dstat, list);
    list->dir = dir;
    list->name = ft_strdup(dir->d_name);
    if(S_ISLINK((list)->st_mode))
        ft_linkpath(list, newpath, flags);
        return(list);
}