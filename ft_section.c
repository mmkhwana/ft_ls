#include "ft_ls.h"

void        *ft_sectionsetup(char *dir, t_flags flags, t_dir *var)
{
    if (!(var->dire = opendir(dir)))
    {
        return (NULL);
    }
    if (!(var->diropt = readdir(var->dire)))
    {
        ft_putendl("readdir problem");
        exit(1);
    }
    if (!(var->files = ft_newlist(var->diropt, dir,flags)))
    {
        ft_putendl("listnew problem");
        exit(1);
    }
    while (var->diropt = readdir(var->dire))
    {
        ft_list(&var->files, var->diropt, dir, flags);
    }
    return(var->files);
}

void        ft_displaysection(int section, t_flags flags)
{
    if (flags.l == 1)
    {
        ft_putstr("total ");
        ft_putnbr(section);
        ft_putchar('\n');
    }
}

void        ft_section(char *dir, t_flags flags)
{
    t_dir       var;
    int         section;
    t_files     *temp;

    block = 0;
    var.files = NULL;
    ft_sectionsetup(dir, flags, &var);
    temp = var.files;
    if (!var.files)
        return ;
    while (var.files->next)
    {
        if (ft_strcmp(var.files->name, ".") != 0 && ft_strcmp(var.files->name, "..")
            != 0 && var.files->name[0] == '.' && flags.a != 1)
        {
            var.files = var.files->next;
        }
        else
        {
            section += (int)var.files->st_blocks;
            var.files = var.files->next;
        }
    }
    section += (int)var.files->st_blocks;
    closedir(var.dire);
    ft_freelist(temp);
    ft_displaysection(section, flags);
}