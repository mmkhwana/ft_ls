#include "../ft_ls.h"

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