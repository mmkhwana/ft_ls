#include "../ft_ls.h"

t_files         *ft_config_arange(char *dir, t_flags flags)
{
    t_dir       opt;

    if (!(opt.dire = opendir(dir)))
    {
        ft_putstr("ls: ");
        ft_putstr(dir);
        ft_putstr(": ");
        ft_putendl(strerror(errno));
        return (NULL);
    }
    if (!(opt.diropt = readdir(opt.dire)))
    {
        ft_putendl_fd("readdir problem", 1);
        exit(1);
    }
    if (!(opt.files = ft_newlist(opt.diropt, dir, flags)))
    {
        ft_putendl_fd("listnew problem", 1);
        exit(1);
    }
    while ((opt.diropt = readdir(opt.dire)))
        ft_list(&opt.files, opt.diropt, dir, flags);
    closedir(opt.dire);
    return (opt.files);   
}