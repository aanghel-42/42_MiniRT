#include "../../inc/minirt.h"

int	ft_get_color_cy(t_minirt *minirt, int color, double closer, t_ray *ray)
{
	double	distance;

	while (minirt->cylinders)
	{
		distance = ft_hit_cylinder(minirt->cylinders, ray->origin, \
			ray->direction);
		if (distance > 0 && distance < closer)
		{
			closer = distance;
			color = ft_color_cy(minirt, distance); // TODO Change minirt with ray
		}
		minirt->cylinders->check = false;
		if (!(minirt->cylinders->next))
			break ;
		minirt->cylinders = minirt->cylinders->next;
	}
	return (color);
}

int	ft_get_color_sp(t_minirt *minirt, int color, double closer, t_ray *ray)
{
	double	distance;

	while (minirt->spheres)
	{	
		distance = ft_hit_sphere(minirt->spheres, ray->direction, \
			ray->direction);
		if (distance > 0 && distance < closer)
		{
			closer = distance;
			color = ft_color_sp(minirt, distance); // TODO Change minirt with ray
		}
		minirt->spheres->check = false;
		if (!(minirt->spheres->next))
			break ;
		minirt->spheres = minirt->spheres->next;
	}
	return (color);
}

int	ft_get_color_pl(t_minirt *minirt, int color, double closer, t_ray *ray)
{
	double	distance;

	while (minirt->planes)
	{
		distance = ft_hit_plane(minirt->planes, ray->origin, \
			ray->direction);
		if (distance > 0 && distance < closer)
		{
			closer = distance;
			color = ft_color_pl(minirt, distance); // TODO Change minirt with ray
		}
		minirt->planes->check = false;
		if (!(minirt->planes->next))
			break ;
		minirt->planes = minirt->planes->next;
	}
	return (color);
}
