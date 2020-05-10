#include "../ft_ls.h"

t_lists    ft_arange_fist(char *dir, t_flags flags)
{
    t_lists     make;

    if (!(make.files = ft_config_arange(dir, flags)))
        return(make);
    make.temp = make.files;
    if (flags.f == 0)
    {
        ft_insertionorder(&make.temp, flags);
    }
    if (flags.f == 1)
    {
        make.tempSec = make.files;
    }
    else if (flags.rr == 1)
    {
        make.temp = ft_reverse(make.temp);
        make.tempSec = make.temp;
        make.files = make.temp;
    }
    else if (flags.t)
    {
            make.tempSec = make.temp;
            make.files = make.temp;
    }
    else
    {
        make.tempSec = make.files;
    }
    return (make);      
}