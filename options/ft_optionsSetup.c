#include "../ft_ls.h"

t_files         *ft_optionsSetup(char **av, t_files *file, t_main main)
{
    t_files     *tmp;
    t_files     *temp;

    tmp = NULL;
    if (file == NULL && av[main.start] != NULL)
    {
        file = ft_listOptions(main.pwd, av[main.start++], main.flags);
    }
    tmp = file;
    while (av[main.start] != NULL)
    {
        temp = ft_listOptions(main.pwd, av[main.start], main.flags);
        if (temp != NULL)
        {
            file->next = temp;
            file = file->next;
        }
        main.start++;
    }
    return (temp);
}