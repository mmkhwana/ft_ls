#include "ft_ls.h"

void    ft_freelist(t_files *files)
{
    t_files     *current;

    current = files;
    while (current != NULL)
    {
        files = files->next;
        free(current->name);
        if (S_ISLINK((current)->st_mode))
        {
            free(current->link);
        }
        free(current);
    }
}

void        ft_freelistprv(t_files *files)
{
    t_files     *current;

    current = files;
    while (current != NULL)
    {
        files = files->prev;
        free(current->name);
        if (S_ISLINK((current)->st_mode))
        {
            free(current->link);
        }
        free(current);
    }
}

void        ft_free(t_files *files)
{
    t_files     *current;

    current = files;
    while (current != NULL)
    {
        if (S_ISDIR((files)->st_mode))
        {
            if (((files)->name[0] == '.'
				&& ft_strcmp((files)->name, ".") != 0
				&& ft_strcmp((files)->name, "..") != 0)
				|| (files)->name[0] != '.')
                {
                    ft_free(files->sub_dir);
                }
        }
        files = files->next;
        free(current->name);
        if (S_ISLINIK((current)->st_mode))
        {
            free(current->link);
        }
        free(current);
    }    
}