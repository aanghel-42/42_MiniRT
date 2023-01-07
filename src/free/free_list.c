#include "../../inc/minirt.h"

void	ft_free_cy(t_cy *elements)
{
	elements = ft_rtr_head_cy(elements);
	while (elements)
	{
		free(elements);
		if (!elements->next)
			break ;
		elements = elements->next;
	}
}

void	ft_free_sp(t_sp *elements)
{
	elements = ft_rtr_head_sp(elements);
	while (elements)
	{
		free(elements);
		if (!elements->next)
			break ;
		elements = elements->next;
	}
}

void	ft_free_pl(t_pl *elements)
{
	elements = ft_rtr_head_pl(elements);
	while (elements)
	{
		free(elements);
		if (!elements->next)
			break ;
		elements = elements->next;
	}
}
