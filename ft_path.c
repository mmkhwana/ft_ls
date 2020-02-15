#include "ft_ls.h"

char        *ft_makepath(char *dir, char *file)
{
    char        *new_path;
    size_t      i;

    i = ft_strlen(dir) + ft_strlen(file);
    i = i + 1;

    new_path =  NULL;

    if (!(new_path = (char*)malloc(sizeof(char) * i + 1)))
        return (NULL);
    if (file[0] == '/' || file[0] == '~')
    {
        new_path = ft_strdup(file);
    }
    else
    {
        new_path = ft_strcpy(new_path, dir);
        new_path = ft_strcat(new_path, "/");
        new_path = ft_strcat(new_path, file);
    }
    return(new_path);
    ft_strdel(&new_path);   
}
