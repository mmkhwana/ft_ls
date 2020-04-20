#include "ft_ls.h"

void            ft_directory(t_files *temp, char *dir, t_flags flags)
{
    char        *newpath;

    if(S_ISDIR((temp)->st_mode))
    {
        if (((temp)->name[0] == '.' && ft_strcmp((temp)->name, ".") != 0
		&& ft_strcmp((temp)->name, "..") != 0) || (temp)->name[0] != '.')
        {
            newpath = ft_makepath(dir, (temp)->name);
            if(!flags.a)
            {
                if(temp->name[0] != '.')
                {
                    ft_putchar('\n');
                    ft_putendl(newpath);
                    (temp)->sub_dir = ft_arange(newpath, flags);
                }
            }
        }
        else
        {
            ft_putchar('\n');
            ft_putendl(newpath);
            (temp)->sub_dir = ft_arange(newpath, flags);
        }
        free(newpath);
    }
}

void        *ft_check(char *name)
{
    ft_putstr("ls: ");
    ft_putstr(name);
    ft_putendl(": No such file or directory");
    return(NULL);
}

void        ft_linkpath(t_files *file, char *path, t_flags flags)
{
    size_t      i;
    ssize_t     link_size;
    ssize_t     size;
    char        *link;
    char        buff[1024];
    char        *msg;

    link_size = 0;
    size = 0;
    link_size = readlink(path, buff, sizeof(buff));
    buff[link_size] = '\0';
    if(flags.l == 1)
    {
        i = ft_strlen("->") + ft_strlen(buff);
        if (!(link = (char *)malloc(sizeof(char) * i + 1)))
        {
            msg = "error in malloc link";
            ft_putendl_fd(msg, 1);
            exit(1);
        }
        link = ft_strcpy(link, " -> ");
        if (link_size < 0)
        {
            file->link = ft_strjoin(link, ft_strjoin("private/", path));
        }
        else
        {
            file->link = ft_strjoin(link, buff);
        }
        free(link);  
    }
}