#include "../ft_ls.h"

void            ft_option(char **av, t_main main)
{
    t_files     *file;
    t_files     *tmp;
    t_files     *temp;

    file = ft_listOptions(main.pwd, av[main.start++], main.flags);
    if ((tmp = ft_optionsSetup(av, file, main)) == NULL)
    {
        exit(1);
    }
    if (main.flags.f == 0)
    {
        ft_insertionorder(&tmp, main.flags);
    }
    if (main.flags.rr == 1)
    {
        tmp = ft_reverse(tmp);
    }
    temp = tmp;
    while (temp->next)
    {
        ft_optionsA(temp, main.pwd, main.flags);
        temp = temp->next;
    }
    ft_optionsA(temp, main.pwd, main.flags);
    while (tmp->next)
    {
        ft_optionB(tmp, main.pwd, main.flags);
        tmp = tmp->next;
    }
    ft_optionB(tmp, main.pwd, main.flags);
    ft_free(file);
}