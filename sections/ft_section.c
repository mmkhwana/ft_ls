#include "../ft_ls.h"

void        ft_section(char *dir, t_flags flags)
{
    t_dir       var;
    int         section;
    t_files     *temp;

    section = 0;
    var.files = NULL;
    ft_sectionsetup(dir, flags, &var);
    temp = var.files;
    if (!var.files)
        return ;
    while (var.files->next != NULL)
    {
        if (ft_strcmp(var.files->name, ".") != 0 && ft_strcmp(var.files->name, "..")
            != 0 && var.files->name[0] == '.' && flags.l != 0)
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
    free(temp);
    ft_displaysection(section / 2, flags);
}