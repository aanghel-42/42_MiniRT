#include "../inc/minirt.h"

void	ft_init_mlx(t_minirt *minirt)
{
	minirt->mlx = (t_mlx *)malloc(sizeof(t_mlx));
	minirt->mlx->mlx_ptr = mlx_init();
	minirt->mlx->w = WIDTH;
	minirt->mlx->h = HEIGHT;
	minirt->mlx->img = mlx_new_image(minirt->mlx->mlx_ptr, \
		minirt->mlx->w, minirt->mlx->h);
	minirt->mlx->addr = mlx_get_data_addr(minirt->mlx->img, &minirt->mlx->bpp, \ 
		&minirt->mlx->w_len, &minirt->mlx->endian);
	minirt->mlx = mlx_new_window(minirt->mlx->mlx_ptr, minirt->mlx->w, \
	minirt->mlx->h, "MiniRT");
}

	// mlx_hook(minirt->mlx->window, 2, 0L, &mlx_key_hook, &minirt);
	// mlx_hook(minirt->mlx->window, 17, 1L << 17, ft_exit, &minirt);
	// mlx_loop(minirt->mlx->mlx_ptr);

void	ft_ray_tracing(t_minirt *minirt)
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