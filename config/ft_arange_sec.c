#include "../ft_ls.h"

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
