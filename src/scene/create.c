#include "../../inc/minirt.h"

void	ft_put_color_scene(t_minirt *minirt)
{
	int		x;
	int		y;
	int		color;

	y = 0;
	while (y < minirt->mlx->h)
	{
		x = 0;
		while (x < minirt->mlx->w)
		{
			// ray = ray_generator(scene, x, y);
			// color = get_hit_color(scene, ray);
			// my_mlx_pixel_put(mlx, x, y, color);
			x++;
		}
		y++;
	}
}

void	ft_create_scene(t_minirt *minirt)
{
	minirt->mlx = (t_mlx *)malloc(sizeof(t_mlx));
	if (!minirt->mlx)
		return ;
	ft_init_mlx(minirt->mlx);
	// ft_put_color_scene(minirt);
	mlx_hook(minirt->mlx->window, 2, 1L << 0, ft_key, minirt);
	mlx_hook(minirt->mlx->window, 17, 0, ft_exit, minirt);
	mlx_loop(minirt->mlx->mlx_ptr);
}