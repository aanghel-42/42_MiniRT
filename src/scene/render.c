#include "../../inc/minirt.h"

t_vec	ray_pixel_to_world(t_minirt *minirt, int x, int y)
{
	double	aspect_ratio;
	double	fov;
	double	p_x;
	double	p_y;

	fov = tanf((double)minirt->camera->fov / 2 * M_PI / 180);
	aspect_ratio = (double)minirt->mlx->w / (double)minirt->mlx->h;
	p_x = (2 * (x + 0.5) / (double)minirt->mlx->w - 1) * aspect_ratio * fov;
	p_y = (1 - 2 * (y + 0.5) / (double)minirt->mlx->h) * fov;
	return (ft_new_vector(-p_x, p_y, 1));
}

t_ray	ray_generator(t_minirt *minirt, int x, int y)
{
	t_vec	shooting_direction;
	t_ray	ray;

	shooting_direction = ray_pixel_to_world(minirt, x, y);
	shooting_direction = ft_subvec(shooting_direction, minirt->camera->cor);
	shooting_direction = ft_normalize_vec(shooting_direction);
	ray = ft_settings_ray(minirt->camera->cor, shooting_direction);
	return (ray);
}
