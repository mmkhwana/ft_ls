#include "ft_ls.h"

int             main(int ac, char **av)
{
    t_main      major;
    t_files     *files;
    t_begin     begin;

    major.pwd = ft_strdup(".");
    ft_defineflags(&major.flags);
    if (ac > 1)
    {
        begin = ft_flag(av, &major.flags);
    }
    major.start = begin.begin;
    if (begin.selected != 0)
    {
        ft_option(av, major);
    }
    else
    {
        if (!(files = ft_arange(".", major.flags)))
        {
            ft_putstr("\0");
            exit(1);
        }
    }
    ft_free(files);
    return (0);
}