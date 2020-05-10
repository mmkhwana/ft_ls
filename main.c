#include "ft_ls.h"

int             main(int ac, char **av)
{
    t_main      main;
    t_files     *files;
    t_begin     begin;

    main.pwd = ft_strdup(".");
    ft_defineflags(&main.flags);
    if (ac > 1)
    {
        begin = ft_flag(av, &main.flags);
    }
    main.start = begin.begin;
    if (begin.selected != 0)
    {
        ft_option(av, main);
    }
    else
    {
        if (!(files = ft_arrange(".", main.flags)))
        {
            ft_putstr("\0");
            exit(1);
        }
        if (main.flags.RR)
        {
            ft_free(files);
        }
        else
        {
            ft_freelist(files);
        }
    }
    return (0);
}