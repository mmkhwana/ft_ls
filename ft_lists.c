#include "ft_ls.h"

void        ft_list(t_files **b, struct dirent *dir, char path, t_flags flags)
{
    t_files     *list;

    list = *b;
    if (!list)
    {
        list = ft_newlist(dir, path, flags);
    }
    else
    {
        while ((list)->next)
        {
            list = list->next;
        }
        list->next = ft_newlist(dir, path, flags);
        list->next->prev = list;
        
    }
}

void        ft_filllist(struct stat opt, t_files *list)
{
    list->next = NULL;
    list->sub_dir = NULL;
    list->d_stat = opt;
    list->mtime = opt.st_mtime;
    list->atime = opt.st_atime;
    list->st_ino = opt.st_ino;
    list->st_size = opt.st_size;
    list->st_mode = opt.st_mode;
    list->st_nlink = opt.st_nlink;
    list->st_uid = opt.st_uid;
    list->st_gid = opt.st_gid;
    list->st_blocks = opt.st_blocks;
}

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

t_files         *ft_reverse(t_files *head)
{
    t_files     *current;
    t_files     *previous;
    t_files     *next;

    curr = head;
    previous = NULL;
    while (curr)
    {
        next = current->next;
        current->next = previous;
        previous = current;
        current = next;
    }
    head = previous;
    return(head);
}