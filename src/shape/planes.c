#include "../../inc/minirt.h"

void	ft_rtr_head_pl(t_pl *pl)
{
	while (pl)
	{
		if (!pl->prev)
			break ;
		pl = pl->prev;
	}
}
