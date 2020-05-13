#include "../ft_ls.h"

void            ft_display(t_files *tmp, t_flags flag)
{
<<<<<<< HEAD
//     if (!flag.a)
//     {
//         if  (tmp->name[0] != '.')
//          {
//                 if (flag.l == 1)
//                 {   
//                     ft_printperm(tmp->d_stat);
//                     ft_perminfo(tmp->d_stat, flag);
//                     ft_timeperm(tmp->d_stat,flag); 
//                     ft_putendl(tmp->name);
//                 }
//         }
//     }
//     else
//     {
=======
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
>>>>>>> 0fb68a1107809ed5b24ff3e6625b365309e45e8c
        
//         if (flag.l == 1)
//         {
//             ft_printperm(tmp->d_stat);
//             ft_perminfo(tmp->d_stat, flag);
//             ft_timeperm(tmp->d_stat,flag);
//         }
//    }

    
<<<<<<< HEAD
    if (flag.l == 2 && flag.a == 1)
=======
    if (flag.a == 1 && flag.l == 2)
>>>>>>> 0fb68a1107809ed5b24ff3e6625b365309e45e8c
    {   
        ft_printperm(tmp->d_stat);
        ft_perminfo(tmp->d_stat, flag);
        ft_timeperm(tmp->d_stat,flag); 
        ft_putendl(tmp->name);
<<<<<<< HEAD
        return ;
=======
        return;
>>>>>>> 0fb68a1107809ed5b24ff3e6625b365309e45e8c
    }

    if (flag.a == 1)
    {
<<<<<<< HEAD
        ft_putendl(tmp->name);
=======
         ft_putendl(tmp->name);
>>>>>>> 0fb68a1107809ed5b24ff3e6625b365309e45e8c
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