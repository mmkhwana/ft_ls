#include "../ft_ls.h"

void        *ft_sectionsetup(char *dir, t_flags flags, t_dir *var)
{
    if (!(var->dire = opendir(dir)))
    {
        return (NULL);
    }
    if (!(var->diropt = readdir(var->dire)))
    {
        ft_putendl("readdir problem");
        exit(1);
    }
    if (!(var->files = ft_newlist(var->diropt, dir,flags)))
    {
        ft_putendl("listnew problem");
        exit(1);
    }
    while ((var->diropt = readdir(var->dire)))
    {
        ft_list(&var->files, var->diropt, dir, flags);
    }
    return(var->files);
}
