#include "../ft_ls.h"

void            ft_display(t_files *tmp, t_flags flag)
{
    //if (!flag.a)
    //{
        // if (tmp->name[0] != '.')
        // {
                // if (flag.l == 1)
                // {   
                //     ft_printperm(tmp->d_stat);
                //     ft_perminfo(tmp->d_stat, flag);
                //     ft_timeperm(tmp->d_stat,flag); 
                //     ft_putendl(tmp->name);
                // }
   //     }
    //}
    //else
    //{
        
//         if (flag.l == 1)
//         {
//             ft_printperm(tmp->d_stat);
//             ft_perminfo(tmp->d_stat, flag);
//             ft_timeperm(tmp->d_stat,flag);
//         }
//    // }

    
    if (flag.a == 1 && flag.l == 2)
    {   
        ft_printperm(tmp->d_stat);
        ft_perminfo(tmp->d_stat, flag);
        ft_timeperm(tmp->d_stat,flag); 
        ft_putendl(tmp->name);
        return;
    }

    if (flag.a == 1)
    {
         ft_putendl(tmp->name);
    }
    if (flag.t == 1)
    {
        ft_putendl(tmp->name);
    }
    if (flag.rr == 1)
    {
        ft_putendl(tmp->name);
    }
    if (flag.RR == 1)
    {
        ft_putendl(tmp->name);
    }  
}