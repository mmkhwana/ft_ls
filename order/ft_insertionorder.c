#include "../ft_ls.h"

void        ft_insertionorder(t_files **heah, t_flags flags)
{
    t_files     *inorder;
    t_files     *curr;
    t_files     *next;

    inorder = NULL;
    curr = *heah;
    while (curr !=NULL)
    {
        next = curr->next;
        if (flags.t == 1 && flags.u == 1)
        {
            ft_timeaccess(&inorder, curr);
        }
        else if (flags.t == 1)
        {
            ft_sort_time_inserted(&inorder, curr);
        }
        else
        {
            ft_orderedinsert(&inorder, curr);   
        }
        curr = next
    }
    *heah = inorder;
}