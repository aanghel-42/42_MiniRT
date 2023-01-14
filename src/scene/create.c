#include "../../inc/minirt.h"

int	ft_get_color(t_minirt *minirt, t_ray *ray)
{
	int		color;
	double	distance;
	double	closer;

	closer = M_INFINITY;
	color = 0x000000;
	if (minirt->cylinders && minirt->cylinders->check)
		color = ft_get_color_cy(minirt, color, closer, ray);
	else if (minirt->spheres && minirt->spheres->check)
		color = ft_get_color_sp(minirt, color, closer, ray);
	else if (minirt->planes && minirt->planes->check)
		color = ft_get_color_pl(minirt, color, closer, ray);
	return (color);
}

void	my_mlx_pixel_put(t_mlx *mlx, int x, int y, int color)
{
	char	*dst;

	if (x >= 0 && x < mlx->w && y >= 0 && y < mlx->h)
	{
		dst = mlx->addr + (y * mlx->w_len + x * (mlx->bpp / 8));
		*(unsigned int *)dst = color;
	}
}

void	ft_put_color_scene(t_minirt *minirt)
{
	int		x;
	int		y;
	int		color;
	t_ray	ray;

	y = 0;
	while (y < minirt->mlx->h)
	{
		x = 0;
		while (x < minirt->mlx->w)
		{
			ray = ray_generator(minirt, x, y);
			color = ft_get_color(minirt, &ray);
			my_mlx_pixel_put(minirt->mlx, x, y, color);
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
	ft_put_color_scene(minirt);
	mlx_hook(minirt->mlx->window, 2, 1L << 0, ft_key, minirt);
	mlx_hook(minirt->mlx->window, 17, 0, ft_exit, minirt);
	mlx_loop(minirt->mlx->mlx_ptr);
}
