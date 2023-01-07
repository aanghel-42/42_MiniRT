#include "../../inc/minirt.h"

void	ft_rtr_head_cy(t_cy *cy)
{
	while (cy)
	{
		if (!cy->prev)
			break ;
		cy = cy->prev;
	}
}
