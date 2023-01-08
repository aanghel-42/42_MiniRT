#include "../../inc/minirt.h"

void	ft_check_ambient(char **row, t_minirt *minirt)
{
	int		r;
	int		g;
	int		b;
	double	light;

	light = ft_atof(row[1]);
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
	minirt->ambient->rgb.r = r;
	minirt->ambient->rgb.g = g;
	minirt->ambient->rgb.b = b;
	minirt->ambient->check = true;
}

void	ft_check_camera(char **row, t_minirt *minirt)
{
	int		fov;
	double	x;
	double	y;
	double	z;

	x = ft_atof(row[4]);
	y = ft_atof(row[5]);
	z = ft_atof(row[6]);
	fov = ft_atoi(row[7]);
	if (minirt->camera->check)
		ft_exit_check(row, minirt, "Camera is present\n");
	if (fov < 0 || fov > 180)
		ft_exit_check(row, minirt, "FOV is incorrect\n");
	if ((x < -1 || x > 1) || (y < -1 || y > 1) || (z < -1 || z > 1))
		ft_exit_check(row, minirt, "Vector 3D Camera is incorrect\n");
	minirt->camera->cor.x = ft_atof(row[1]);
	minirt->camera->cor.y = ft_atof(row[2]);
	minirt->camera->cor.z = ft_atof(row[3]);
	minirt->camera->vec.x = x;
	minirt->camera->vec.y = y;
	minirt->camera->vec.z = z;
	minirt->camera->fov = fov;
	minirt->camera->check = true;
}

void	ft_check_light(char **row, t_minirt *minirt)
{
	int		r;
	int		g;
	int		b;
	double	brightness;

	brightness = ft_atof(row[4]);
	r = ft_atoi(row[5]);
	g = ft_atoi(row[6]);
	b = ft_atoi(row[7]);
	if (minirt->light->check)
		ft_exit_check(row, minirt, "Light is present\n");
	if (brightness < 0.0 || brightness > 1.0)
		ft_exit_check(row, minirt, "Brightness is incorrect\n");
	if ((r < 0 || r > 255) || (g < 0 || g > 255) || (b < 0 || b > 255))
		ft_exit_check(row, minirt, "RGB Light is incorrect\n");
	minirt->light->cor.x = ft_atof(row[1]);
	minirt->light->cor.y = ft_atof(row[2]);
	minirt->light->cor.z = ft_atof(row[3]);
	minirt->light->bright = brightness;
	minirt->light->rgb.r = r;
	minirt->light->rgb.g = g;
	minirt->light->rgb.b = b;
	minirt->light->check = true;
}
