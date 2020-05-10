#include "../ft_ls.h"

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
        if (S_ISLNK((current)->st_mode))
        {
            free(current->link);
        }
        free(current);
    }    
}