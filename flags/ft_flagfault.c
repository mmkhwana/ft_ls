#include "../ft_ls.h"

void        ft_flagfault(char x, char *str, int i)
{
    if (i == 1)
    {
        ft_putstr("ls: illegal option --");
        ft_putchar(x);
        ft_putchar(10);
        ft_putstr("usage: ls [-Ralrtfgu] [file ...]");
        ft_putchar(10);
        ft_putendl("fail");
        exit(1);
    }
    else
    {
        ft_putstr("ls:");
        ft_putstr(str);
        ft_putstr(": No such files or directory");
        ft_putchar(10);
    }
}