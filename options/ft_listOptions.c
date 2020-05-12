#include "../ft_ls.h"

t_files         *ft_listOptions(char *path, char *name, t_flags flags)
{
    t_option    var;

    var.newpath = ft_makepath(path, name);
    if (lstat(var.newpath, &var.fstat) < 0)
    {
        return (ft_check(name));
    }
    free(var.newpath);
    if (!(var.alist = (t_files *)malloc(sizeof(t_files))))
    {
        ft_putendl("LISTOPTION");
        return (NULL);
    }
    var.alist->next = NULL;
    var.alist->sub_dir = NULL;
    var.alist->d_stat = var.fstat;
    var.alist->mtime = var.fstat.st_mtime;
    var.alist->atime = var.fstat.st_atime;
    var.alist->st_mode = var.fstat.st_mode;
    var.alist->st_nlink = var.fstat.st_nlink;
    var.alist->st_uid = var.fstat.st_uid;
    var.alist->st_gid = var.fstat.st_gid;
    var.alist->st_size = var.fstat.st_size;
    var.alist->st_ino = var.fstat.st_ino;
    var.alist->st_blocks = var.fstat.st_blocks;
    var.alist->name = ft_strdup(name);
    if (S_ISLNK((var.alist)->st_mode))
    {
        ft_linkpath(var.alist, var.newpath, flags);
    }
    return (var.alist);
}