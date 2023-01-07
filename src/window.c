#include "../inc/minirt.h"

void	ft_window(t_minirt *minirt)
{
	minirt->mlx_ptr = mlx_init();
	minirt->window = mlx_new_window(minirt->mlx_ptr, minirt->w * 64, \
	minirt->h * 64, "MiniRT");
	mlx_hook(minirt->window, 2, 0L, &mlx_key_hook, &minirt);
	mlx_hook(minirt->window, 17, 1L << 17, &ft_exit, &minirt);
	mlx_loop(minirt->mlx_ptr);
}

