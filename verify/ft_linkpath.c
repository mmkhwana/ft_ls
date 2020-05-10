#include "../ft_ls.h"

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