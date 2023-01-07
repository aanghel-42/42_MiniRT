#include "../../inc/minirt.h"

void	ft_check_sphere(char **row, t_minirt *minirt)
{
	int		r;
	int		g;
	int		b;

	r = ft_atoi(row[5]);
	g = ft_atoi(row[6]);
	b = ft_atoi(row[7]);
	if ((r < 0 || r > 255) || (g < 0 || g > 255) || (b < 0 || b > 255))
		ft_exit_check(row, minirt, "RGB spheres is incorrect\n");
	minirt->spheres->x = ft_atof(row[1]);
	minirt->spheres->y = ft_atof(row[2]);
	minirt->spheres->z = ft_atof(row[3]);
	minirt->spheres->diameter = ft_atof(row[4]);
	minirt->spheres->r = r;
	minirt->spheres->g = g;
	minirt->spheres->b = b;
}

void	ft_check_plane_split(t_minirt *minirt, char **row)
{
	minirt->planes->x = ft_atof(row[1]);
	minirt->planes->y = ft_atof(row[2]);
	minirt->planes->z = ft_atof(row[3]);
}

void	ft_check_plane(char **row, t_minirt *minirt)
{
	int		r;
	int		g;
	int		b;
	double	x;
	double	y_z;

	x = ft_atof(row[4]);
	y_z = ft_atof(row[5]);
	r = ft_atoi(row[7]);
	g = ft_atoi(row[8]);
	b = ft_atoi(row[9]);
	if ((x < -1 || x > 1) || (y_z < -1 || y_z > 1))
		ft_exit_check(row, minirt, "Vector 3D Plane is incorrect\n");
	minirt->planes->vector_y = y_z;
	y_z = ft_atof(row[6]);
	if (y_z < -1 || y_z > 1)
		ft_exit_check(row, minirt, "Vector 3D Plane is incorrect\n");
	if ((r < 0 || r > 255) || (g < 0 || g > 255) || (b < 0 || b > 255))
		ft_exit_check(row, minirt, "RGB plane is incorrect\n");
	minirt->planes->vector_x = x;
	minirt->planes->vector_z = y_z;
	minirt->planes->r = r;
	minirt->planes->g = g;
	minirt->planes->b = b;
	ft_check_plane_split(minirt, row);
}

void	ft_check_cylinders_split(t_minirt *minirt, char **row)
{
	minirt->cylinders->x = ft_atof(row[1]);
	minirt->cylinders->y = ft_atof(row[2]);
	minirt->cylinders->z = ft_atof(row[3]);
	minirt->cylinders->diameter = ft_atof(row[7]);
	minirt->cylinders->height = ft_atof(row[8]);
}

void	ft_check_cylinders(char **row, t_minirt *minirt)
{
	int		r;
	int		g;
	int		b;
	double	x;
	double	y_z;

	x = ft_atof(row[4]);
	y_z = ft_atof(row[5]);
	r = ft_atoi(row[9]);
	g = ft_atoi(row[10]);
	b = ft_atoi(row[11]);
	if ((x < -1 || x > 1) || (y_z < -1 || y_z > 1))
		ft_exit_check(row, minirt, "Vector 3D Cylinder is incorrect\n");
	minirt->cylinders->vector_y = y_z;
	y_z = ft_atof(row[6]);
	if (y_z < -1 || y_z > 1)
		ft_exit_check(row, minirt, "Vector 3D Cylinder is incorrect\n");
	if ((r < 0 || r > 255) || (g < 0 || g > 255) || (b < 0 || b > 255))
		ft_exit_check(row, minirt, "RGB Cylinder is incorrect\n");
	minirt->cylinders->vector_x = x;
	minirt->cylinders->vector_z = y_z;
	minirt->cylinders->r = r;
	minirt->cylinders->g = g;
	minirt->cylinders->b = b;
	ft_check_cylinders_split(minirt, row);
}
