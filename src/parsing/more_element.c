#include "../../inc/minirt.h"

void	ft_check_sphere(char **row, t_minirt *minirt)
{
	int		r;
	int		g;
	int		b;

	r = ft_atoi(row[5]);
	g = ft_atoi(row[6]);
	b = ft_atoi(row[7]);
	if (minirt->spheres->check)
	{
		minirt->spheres->next = (t_sp *)malloc(sizeof(t_sp));
		minirt->spheres->next->prev = minirt->spheres;
		minirt->spheres = minirt->spheres->next;
	}
	if ((r < 0 || r > 255) || (g < 0 || g > 255) || (b < 0 || b > 255))
		ft_exit_check(row, minirt, "RGB spheres is incorrect\n");
	minirt->spheres->x = ft_atof(row[1]);
	minirt->spheres->y = ft_atof(row[2]);
	minirt->spheres->z = ft_atof(row[3]);
	minirt->spheres->diameter = ft_atof(row[4]);
	minirt->spheres->r = r;
	minirt->spheres->g = g;
	minirt->spheres->b = b;
	minirt->spheres->next = NULL;
	minirt->spheres->check = true;
}

void	ft_check_plane_split(t_minirt *minirt, char **row)
{
	if ((minirt->planes->vx < -1 || minirt->planes->vx > 1) \
	|| (minirt->planes->vy < -1 || minirt->planes->vy > 1) \
	|| (minirt->planes->vz < -1 || minirt->planes->vz > 1))
		ft_exit_check(row, minirt, "Vector 3D Plane is incorrect\n");
	minirt->planes->x = ft_atof(row[1]);
	minirt->planes->y = ft_atof(row[2]);
	minirt->planes->z = ft_atof(row[3]);
	minirt->planes->next = NULL;
	minirt->planes->check = true;
}

void	ft_check_plane(char **row, t_minirt *minirt)
{
	int		r;
	int		g;
	int		b;

	r = ft_atoi(row[7]);
	g = ft_atoi(row[8]);
	b = ft_atoi(row[9]);
	if (minirt->planes->check)
	{
		minirt->planes->next = (t_pl *)malloc(sizeof(t_pl));
		minirt->planes->next->prev = minirt->planes;
		minirt->planes = minirt->planes->next;
	}
	if ((r < 0 || r > 255) || (g < 0 || g > 255) || (b < 0 || b > 255))
		ft_exit_check(row, minirt, "RGB plane is incorrect\n");
	minirt->planes->vx = ft_atof(row[4]);
	minirt->planes->vy = ft_atof(row[5]);
	minirt->planes->vz = ft_atof(row[6]);
	minirt->planes->r = r;
	minirt->planes->g = g;
	minirt->planes->b = b;
	ft_check_plane_split(minirt, row);
}

void	ft_check_cylinders_split(t_minirt *minirt, char **row)
{
	if ((minirt->cylinders->vx < -1 || minirt->cylinders->vx > 1) \
	|| (minirt->cylinders->vy < -1 || minirt->cylinders->vy > 1) \
	|| (minirt->cylinders->vz < -1 || minirt->cylinders->vz > 1))
		ft_exit_check(row, minirt, "Vector 3D Plane is incorrect\n");
	minirt->cylinders->x = ft_atof(row[1]);
	minirt->cylinders->y = ft_atof(row[2]);
	minirt->cylinders->z = ft_atof(row[3]);
	minirt->cylinders->diameter = ft_atof(row[7]);
	minirt->cylinders->height = ft_atof(row[8]);
	minirt->cylinders->next = NULL;
	minirt->planes->check = true;
}

void	ft_check_cylinders(char **row, t_minirt *minirt)
{
	int		r;
	int		g;
	int		b;

	r = ft_atoi(row[9]);
	g = ft_atoi(row[10]);
	b = ft_atoi(row[11]);
	if (minirt->cylinders->check)
	{
		minirt->cylinders->next = (t_cy *)malloc(sizeof(t_cy));
		minirt->cylinders->next->prev = minirt->cylinders;
		minirt->cylinders = minirt->cylinders->next;
	}
	if ((r < 0 || r > 255) || (g < 0 || g > 255) || (b < 0 || b > 255))
		ft_exit_check(row, minirt, "RGB Cylinder is incorrect\n");
	minirt->cylinders->vx = ft_atof(row[4]);
	minirt->cylinders->vy = ft_atof(row[5]);
	minirt->cylinders->vz = ft_atof(row[6]);
	minirt->cylinders->r = r;
	minirt->cylinders->g = g;
	minirt->cylinders->b = b;
	ft_check_cylinders_split(minirt, row);
}
