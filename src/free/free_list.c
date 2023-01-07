#include "../../inc/minirt.h"

void	ft_free_cy(t_cy *elements)
{
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
	while (elements)
	{
		free(elements);
		if (!elements->next)
			break ;
		elements = elements->next;
	}
}
