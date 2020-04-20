#include "ft_ls.h"

void        ft_arange_sec(t_files *files, char *dir, t_flags flags)
{
    t_files     *temp;
    temp = files;
    while (temp->next)
    {
        ft_directory(temp, dir, flags);
        temp = temp->next;
    }
    ft_directory(temp, dir, flags);
}

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
    while (opt.diropt = readdir(opt.dire))
        ft_list(&opt.files, opt.diropt, dir, flags);
    closedir(opt.dire);
    return (opt.files);
    
}

t_lists    ft_arange_fist(char *dir, t_flags flags)
{
    t_lists     make;

    if (!(make.files = ft_config_arange(dir, flags)))
        return(make);
    make.temp = make.files;
    if (flags.f == 0)
    {
        ft_insertionOrder(&make.temp, flags);
    }
    if (flags.f == 1)
    {
        make.tempSec = make.files;
    }
    else if (flags.sm_r == 1)
    {
        make.temp = ft_reverse(make.temp);
        make.tempSec = make.temp;
        make.files = make.temp;
    }
    else if (flags.t)
    {
            make.tempSec = make.temp;
            make.files = make.temp
    }
    else
    {
        make.tempSec = make.files;
    }
    return (make);
    
    
    
}