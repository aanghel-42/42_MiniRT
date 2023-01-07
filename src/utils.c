#include "../inc/minirt.h"

int	ft_exit(t_minirt *minirt)
{
	ft_exit_check(NULL, minirt, NULL);
	mlx_destroy_window(minirt->mlx_ptr, minirt->window);
	exit(0);
	return (0);
}
