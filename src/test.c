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
