#include "../ft_ls.h"

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