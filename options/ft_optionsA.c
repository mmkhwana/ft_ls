#include "../ft_ls.h"

void            ft_optionsA(t_files *temp, char *pwd, t_flags flags)
{
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
    if (S_ISDIR(temp->st_mode))
    {
        if (!(flags.l == 2 ))
        {
            ft_display(temp, flags);
        }
    }
    //free(newpath);
}