#include "../ft_ls.h"

void            ft_optionB(t_files *temp, char *pwd, t_files flags)
{
    t_files     *file;
    char        *newpath;
    struct stat fstat;

    newpath = ft_makepath(pwd, temp->name);
    if (lstat(newpath, &fstat) < 0)
    {
        ft_putstr("ls: ");
        ft_putstr(temp->name);
        ft_putstr(": No such file or directory");
        ft_putchar(10);
    }
    else
    {
        if (S_ISDIR(temp->st_mode))
        {
            ft_putchar('\n');
            ft_putendl(newpath);
            file = ft_arrange(newpath, flags);
            ft_free(file);
        }
    }
    free(newpath);   
}