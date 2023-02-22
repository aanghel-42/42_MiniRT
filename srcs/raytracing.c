#include "../includes/minirt.h"

//function that generates the view from the cam
t_ray	ft_ray_generation(t_main *main, int x, int y)
{
	t_vec3	tmp;
	t_ray	res;
	float	u;
	float	v;

	u = (((float)x * 2.0f) / (float)main->mlx.x_res - 1.0f) * main->cam.h;
	v = (((float)y * -2.0f) / (float)main->mlx.y_res + 1.0f) * main->cam.w;
	res.direction = ft_vec_float_multi(u, main->cam.right);
	tmp = ft_vec_float_multi(v, main->cam.up);
	res.direction = ft_vec_addition(tmp, res.direction);
	res.direction = ft_vec_addition(res.direction, main->cam.forward);
	res.direction = ft_normalize(res.direction);
	res.origin = main->cam.pos;
	return (res);
}

//function that colors every single pixel
void	ft_pixel_color(t_main *main, t_ray ray, int x, int y)
{
	t_vec3	rgb;
	t_vec3	rgb_l;
	t_vec3	light_pos;
	float	l;
	int		i;

	light_pos = ft_find_in_tab(&main->scn, 'L')->pos;
	i = -1;
	ray.i_close = -1;
	while (++i < main->scn.n_obj)
		ft_check_intersection(main->scn.obj[i], i, &ray);
	if (ray.i_close > -1)
	{
		l = ft_shadow_value(ray, light_pos, main->scn);
		rgb_l = ft_vec_float_multi(l, main->scn.obj[ray.i_close].rgb);
		rgb = ft_vec_float_multi(ft_find_in_tab(&main->scn, 'A')->light_r,
				ft_find_in_tab(&main->scn, 'A')->rgb);
		rgb = ft_vec_addition(rgb_l, rgb);
		ft_color_max(&rgb);
		ft_put_pixel_color(&main->mlx, x, y, rgb);
	}
	else
		ft_put_pixel_color(&main->mlx, x, y, ft_new_vec(0.0f, 0.0f, 0.0f));
}

//function that renders the data on scrren and inserts it in the window
int	ft_frame_loop(t_main *main)
{
	int	x;
	int	y;

	ft_image_init(&main->mlx);
	ft_camera_update(main);
	y = 0;
	while (y < main->mlx.y_res)
	{
		x = 0;
		while (x < main->mlx.x_res)
		{
			ft_pixel_color(main, ft_ray_generation(main, x, y), x, y);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(main->mlx.ptr, main->mlx.window, \
			main->mlx.img.ptr, 0, 0);
	mlx_destroy_image(main->mlx.ptr, main->mlx.img.ptr);
	printf("Rendering Done\n");
	return (1);
}
