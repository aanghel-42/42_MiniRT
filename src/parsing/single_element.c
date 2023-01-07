#include "../../inc/minirt.h"

void	ft_check_ambient(char **row, t_minirt *minirt)
{
	int		r;
	int		g;
	int		b;
	float	light;

	light = ft_atoi(row[1]);
	r = ft_atoi(row[2]);
	g = ft_atoi(row[3]);
	b = ft_atoi(row[4]);
	if (minirt->ambient->check)
		ft_exit_check(row, minirt, "Ambient is present\n");
	if (light < 0.0 || light > 1.0)
		ft_exit_check(row, minirt, "Light is incorrect\n");
	if ((r < 0 || r > 255) || (g < 0 || g > 255) || (b < 0 || b > 255))
		ft_exit_check(row, minirt, "RGB Ambient is incorrect\n");
	minirt->ambient->light = light;
	minirt->ambient->r = r;
	minirt->ambient->g = g;
	minirt->ambient->b = b;
	minirt->ambient->check = true;
}

void	ft_check_camera(char **row, t_minirt *minirt)
{
	int		fov;
	float	x;
	float	y;
	float	z;

	x = ft_atoi(row[4]);
	y = ft_atoi(row[5]);
	z = ft_atoi(row[6]);
	fov = ft_atoi(row[7]);
	if (minirt->camera->check)
		ft_exit_check(row, minirt, "Camera is present\n");
	if (fov < 0 || fov > 180)
		ft_exit_check(row, minirt, "FOV is incorrect\n");
	if ((x < -1 || x > 1) || (y < -1 || y > 1) || (z < -1 || z > 1))
		ft_exit_check(row, minirt, "Vector 3D Camera is incorrect\n");
	minirt->camera->x = ft_atoi(row[1]);
	minirt->camera->y = ft_atoi(row[2]);
	minirt->camera->z = ft_atoi(row[3]);
	minirt->camera->vector_x = x;
	minirt->camera->vector_y = y;
	minirt->camera->vector_z = z;
	minirt->camera->fov = fov;
	minirt->camera->check = true;
}

void	ft_check_light(char **row, t_minirt *minirt)
{
	int		r;
	int		g;
	int		b;
	float	brightness;

	brightness = ft_atoi(row[4]);
	r = ft_atoi(row[5]);
	g = ft_atoi(row[6]);
	b = ft_atoi(row[7]);
	if (minirt->light->check)
		ft_exit_check(row, minirt, "Light is present\n");
	if (brightness < 0.0 || brightness > 1.0)
		ft_exit_check(row, minirt, "Brightness is incorrect\n");
	if ((r < 0 || r > 255) || (g < 0 || g > 255) || (b < 0 || b > 255))
		ft_exit_check(row, minirt, "RGB Light is incorrect\n");
	minirt->light->x = ft_atoi(row[1]);
	minirt->light->y = ft_atoi(row[2]);
	minirt->light->z = ft_atoi(row[3]);
	minirt->light->bright = brightness;
	minirt->light->r = r;
	minirt->light->g = g;
	minirt->light->b = b;
	minirt->light->check = true;
}
