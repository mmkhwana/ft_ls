#include "../ft_ls.h"

void        *ft_check(char *name)
{
    ft_putstr("ls: ");
    ft_putstr(name);
    ft_putendl(": No such file or directory");
    return (NULL);
}
