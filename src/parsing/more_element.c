#include "../../inc/minirt.h"

void	ft_check_sphere(char **row, t_minirt *minirt)
{
	int		r;
	int		g;
	int		b;
	t_sp	*tmp;

	r = ft_atoi(row[5]);
	g = ft_atoi(row[6]);
	b = ft_atoi(row[7]);
	if (minirt->spheres->check)
		minirt->spheres = ft_lstadd_back_sp(minirt->spheres, \
		ft_lstnew_sp(minirt->spheres));
	if ((r < 0 || r > 255) || (g < 0 || g > 255) || (b < 0 || b > 255))
		ft_exit_check(row, minirt, "RGB spheres is incorrect\n");
	minirt->spheres->cor.x = ft_atof(row[1]);
	minirt->spheres->cor.y = ft_atof(row[2]);
	minirt->spheres->cor.z = ft_atof(row[3]);
	minirt->spheres->diameter = ft_atof(row[4]);
	minirt->spheres->rgb.r = r;
	minirt->spheres->rgb.g = g;
	minirt->spheres->rgb.b = b;
	minirt->spheres->check = true;
}

void	ft_check_plane_split(t_minirt *minirt, char **row)
{
	if ((minirt->planes->vec.x < -1 || minirt->planes->vec.x > 1) \
	|| (minirt->planes->vec.y < -1 || minirt->planes->vec.y > 1) \
	|| (minirt->planes->vec.z < -1 || minirt->planes->vec.z > 1))
		ft_exit_check(row, minirt, "Vector 3D Plane is incorrect\n");
	minirt->planes->cor.x = ft_atof(row[1]);
	minirt->planes->cor.y = ft_atof(row[2]);
	minirt->planes->cor.z = ft_atof(row[3]);
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
		minirt->planes = ft_lstadd_back_pl(minirt->planes, \
		ft_lstnew_pl(minirt->planes));
	if ((r < 0 || r > 255) || (g < 0 || g > 255) || (b < 0 || b > 255))
		ft_exit_check(row, minirt, "RGB plane is incorrect\n");
	minirt->planes->vec.x = ft_atof(row[4]);
	minirt->planes->vec.y = ft_atof(row[5]);
	minirt->planes->vec.z = ft_atof(row[6]);
	minirt->planes->rgb.r = r;
	minirt->planes->rgb.r = g;
	minirt->planes->rgb.r = b;
	ft_check_plane_split(minirt, row);
}

void	ft_check_cylinders_split(t_minirt *minirt, char **row)
{
	if ((minirt->cylinders->vec.x < -1 || minirt->cylinders->vec.x > 1) \
	|| (minirt->cylinders->vec.y < -1 || minirt->cylinders->vec.y > 1) \
	|| (minirt->cylinders->vec.z < -1 || minirt->cylinders->vec.z > 1))
		ft_exit_check(row, minirt, "Vector 3D Plane is incorrect\n");
	minirt->cylinders->cor.x = ft_atof(row[1]);
	minirt->cylinders->cor.y = ft_atof(row[2]);
	minirt->cylinders->cor.y = ft_atof(row[3]);
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
		minirt->cylinders = ft_lstadd_back_cy(minirt->cylinders, \
		ft_lstnew_cy(minirt->cylinders));
	if ((r < 0 || r > 255) || (g < 0 || g > 255) || (b < 0 || b > 255))
		ft_exit_check(row, minirt, "RGB Cylinder is incorrect\n");
	minirt->cylinders->vec.x = ft_atof(row[4]);
	minirt->cylinders->vec.y = ft_atof(row[5]);
	minirt->cylinders->vec.z = ft_atof(row[6]);
	minirt->cylinders->rgb.r = r;
	minirt->cylinders->rgb.g = g;
	minirt->cylinders->rgb.b = b;
	ft_check_cylinders_split(minirt, row);
}
