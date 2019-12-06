

#include    "ft_ls.h"
void        ft_printperm(struct stat d_stat)
{
    ft_dirperm(d_stat);
    ft_memeberperm(d_stat);
    ft_diffperm(d_stat);
}