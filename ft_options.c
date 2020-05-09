#include "ft_ls.h"

t_files *ft_listOptions(char *path, char *name, t_flags flags)
{
    t_option    var;

    var.newpath = ft_makepath(path, name);
    if (lstat(var.newpath, &var.fstat) < 0)
    {
        return (ft_check(name));
    }
    free(var.newpath);
    if (!(var.alist = (t_files *)malloc(sizeof(t_files))))
    {
        return (NULL);
    }
    var.alist->next = NULL;
    var.alist->sub_dir = NULL;
    var.alist->d_stat = var.fstat;
    var.alist->mtime = var.fstat.st_mtime;
    var.alist->atime = var.fstat.st_atime;
    var.alist->st_mode = var.fstat.st_mode;
    var.alist->st_nlink = var.fstat.st_nlink;
    var.alist->st_uid = var.fstat.st_uid;
    var.alist->st_gid = var.fstat.st_gid;
    var.alist->st_size = var.fstat.st_size;
    var.alist->st_ino = var.fstat.st_ino;
    var.alist->st_blocks = var.fstat.st_blocks;
    var.alist->name = ft_strdup(name);
    if (S_ISLINK((var.alist)->st_mode))
    {
        ft_linkpath(var.alist, var.newpath, flags);
    }
    return (var.alist);
}

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
    if (!S_ISDIR(temp->st_mode))
    {
        ft_display(temp, flags);
    }
    free(newpath);
}

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

t_files         *ft_optionsSetup(char **av, t_files *file, t_main main)
{
    t_files     *tmp;
    t_files     *temp;

    tmp = NULL;
    if (file == NULL && av[main.start] != NULL)
    {
        file = ft_listOptions(main.pwd, av[main.start++], main.flags);
    }
    tmp = file;
    while (av[main.start] != NULL)
    {
        temp = ft_listOptions(main.pwd, av[main.start], main.flags);
        if (temp != NULL)
        {
            file->next = temp;
            file = file->next;
        }
        main.start++;
    }
    return (temp);
}

void            ft_option(char **av, t_main main)
{
    t_files     *file;
    t_files     *tmp;
    t_files     *temp;

    file = ft_listOptions(main.pwd, av[main.start++], main.flags);
    if ((tmp = ft_optionsSetup(av, file, main)) == NULL)
    {
        exit(1);
    }
    if (main.flags.f == 0)
    {
        ft_insertionorder(&tmp, main.flags);
    }
    if (main.flags.sm_r == 1)
    {
        tmp = ft_reverse(tmp);
    }
    temp = tmp;
    while (temp->next)
    {
        ft_optionsA(temp, main.pwd, main.flags);
        temp = temp->next;
    }
    ft_optionsA(temp, main.pwd, main.flags);
    while (tmp->next)
    {
        ft_optionB(tmp, main.pwd, main.flags);
        tmp = tmp->next;
    }
    ft_optionB(tmp, main.pwd, main.flags);
    ft_free(file);
}