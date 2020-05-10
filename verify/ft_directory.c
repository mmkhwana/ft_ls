#include "../ft_ls.h"

void            ft_directory(t_files *temp, char *dir, t_flags flags)
{
    char        *newpath;

    if(S_ISDIR((temp)->st_mode))
    {
        if (((temp)->name[0] == '.' && ft_strcmp((temp)->name, ".") != 0
		&& ft_strcmp((temp)->name, "..") != 0) || (temp)->name[0] != '.')
        {
            newpath = ft_makepath(dir, (temp)->name);
            if(!flags.a)
            {
                if(temp->name[0] != '.')
                {
                    ft_putchar('\n');
                    ft_putendl(newpath);
                    (temp)->sub_dir = ft_arange(newpath, flags);
                }
            }
            else
            {
                ft_putchar('\n');
                ft_putendl(newpath);
                (temp)->sub_dir = ft_arange(newpath, flags);
            }
            free(newpath);
        }
    }
}
