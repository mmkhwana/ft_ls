#include "../ft_ls.h"

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