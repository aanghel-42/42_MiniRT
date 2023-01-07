#include "../inc/minirt.h"

void	ft_print_lst_ambient(t_a *token)
{
	t_a	*a;

	a = token;
	printf("%d -- R\n", a->r);
	printf("%d -- G\n", a->g);
	printf("%d -- B\n", a->b);
	printf("%d -- Bool Check\n", a->check);
	printf("%lf -- Light\n", a->light);
}

void	ft_print_plane(t_pl *planes)
{
	while (planes)
	{
		printf("%d,%d,%d --- RGB\n", planes->r, planes->g, planes->b);
		printf("%lf - %lf - %lf --- Coord X - Y - Z\n", planes->x, planes->y, planes->z);
		printf("%lf - %lf - %lf --- Vector X - Y - Z\n", planes->vx, planes->vy, planes->vz);
		printf("%d --- Check\n", planes->check);
		if (!planes->next)
			break ;
		planes = planes->next;
	}
}
