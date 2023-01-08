#include "../inc/minirt.h"

void	ft_print_lst_ambient(t_a *token)
{
	t_a	*a;

	a = token;
	printf("%d -- R\n", a->rgb.r);
	printf("%d -- G\n", a->rgb.g);
	printf("%d -- B\n", a->rgb.b);
	printf("%d -- Bool Check\n", a->check);
	printf("%lf -- Light\n", a->light);
}

void	ft_print_spheres(t_sp *spheres)
{
	int		i;
	t_sp	*token;

	i = 0;
	spheres = ft_rtr_head_sp(spheres);
	token = spheres;
	while (token)
	{
		printf("________________________________________________\n\n");
		printf("Nodo: %d\n", i);
		printf("%lf - %lf - %lf --- Coord X - Y - Z\n", \
			token->cor.x, token->cor.y, token->cor.z);
		printf("%lf --- Diameter\n", token->diameter);
		printf("%d,%d,%d --- RGB\n", token->rgb.r, \
			token->rgb.g, token->rgb.b);
		printf("%d --- Check\n", token->check);
		printf("________________________________________________\n\n");
		if (!token->next)
			break ;
		token = token->next;
		i++;
	}
}

void	ft_print_planes(t_pl *planes)
{
	int		i;
	t_pl	*token;

	i = 0;
	planes = ft_rtr_head_pl(planes);
	token = planes;
	while (token)
	{
		printf("________________________________________________\n\n");
		printf("Nodo: %d\n", i);
		printf("%lf - %lf - %lf --- Coord X - Y - Z\n", \
			token->cor.x, token->cor.y, token->cor.z);
		printf("%lf - %lf - %lf --- Vector X - Y - Z\n", \
		token->vec.x, token->vec.y, token->vec.z);
		printf("%d,%d,%d --- RGB\n", token->rgb.r, \
			token->rgb.g, token->rgb.b);
		printf("%d --- Check\n", token->check);
		printf("________________________________________________\n\n");
		if (!token->next)
			break ;
		token = token->next;
		i++;
	}
}

void	ft_print_cylinders(t_cy *cylinders)
{
	int		i;
	t_cy	*token;

	i = 0;
	cylinders = ft_rtr_head_cy(cylinders);
	token = cylinders;
	while (token)
	{
		printf("________________________________________________\n\n");
		printf("Nodo: %d\n", i);
		printf("%lf - %lf - %lf --- Coord X - Y - Z\n", \
			token->cor.x, token->cor.y, token->cor.z);
		printf("%lf - %lf - %lf --- Vector X - Y - Z\n", \
			token->vec.x, token->vec.y, token->vec.z);
		printf("%lf --- Diameter\n", token->diameter);
		printf("%lf --- Height\n", token->height);
		printf("%d,%d,%d --- RGB\n", token->rgb.r, \
			token->rgb.g, token->rgb.b);
		printf("%d --- Check\n", token->check);
		printf("________________________________________________\n\n");
		if (!token->next)
			break ;
		token = token->next;
		i++;
	}
}