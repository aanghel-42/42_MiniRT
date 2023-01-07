#include "../../inc/minirt.h"

void	ft_rtr_head_sp(t_sp *sp)
{
	while (sp)
	{
		if (!sp->prev)
			break ;
		printf("CIAO\n");
		sp = sp->prev;
	}
}

void	ft_init_sp(t_sp	*sp)
{
	
}
