#include "../ft_ls.h"

void        ft_printperm(struct stat d_stat)
{
    ft_permission(d_stat);
    ft_memberperm(d_stat);
    ft_diffperm(d_stat);
}