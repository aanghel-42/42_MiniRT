#include "../includes/minirt.h"

//function that checks if a sphere has been hit
float	ft_hit_sphere(t_vec3 center, float radius, t_ray ray)
{
	t_vec3	oc;
	t_poly	poly;
	t_inter	res;

	oc = ft_vec_minus(ray.origin, center);
	poly.a = ft_dot(ray.direction, ray.direction);
	poly.b = 2.0f * ft_dot(oc, ray.direction);
	poly.c = ft_dot(oc, oc) - (radius * radius);
	res.discri = poly.b * poly.b - (4.0f * poly.a * poly.c);
	if (res.discri < 0.0f)
		return (-1.0f);
	res.t1 = (-poly.b - sqrtf(res.discri)) / (2.0f * poly.a);
	if (res.t1 > 0.0f)
		return (fabsf(res.t1));
	return (res.t1);
}

//function that checks if a plane has been hit
float	ft_hit_plane(t_vec3 pos, t_vec3 dir, t_ray ray)
{
	float	denom;
	float	t;
	t_vec3	diff;

	t = 0;
	denom = ft_dot(dir, ray.direction);
	if (fabs(denom) > 0.0000001f)
	{
		diff = ft_vec_minus(pos, ray.origin);
		t = ft_dot(diff, dir);
		t = t / denom;
		return (t);
	}
	return (-1.0f);
}

//function that checks if a cylinder has been hit
float	ft_hit_cylinder(t_obj obj, t_ray ray)
{
	t_ray	new_ray;
	t_vec3	oc;
	t_poly	poly;
	t_inter	res;

	obj.vec = ft_normalize(obj.vec);
	new_ray.origin = ray.origin;
	new_ray.direction = ft_cross(ray.direction, obj.vec);
	oc = ft_vec_minus(ray.origin, obj.pos);
	poly.a = ft_dot(new_ray.direction, new_ray.direction);
	poly.b = 2.0f * ft_dot(new_ray.direction, ft_cross(oc, obj.vec));
	poly.c = ft_dot(ft_cross(oc, obj.vec), ft_cross(oc, obj.vec))
		- powf(0.5f * obj.diameter, 2);
	res.discri = poly.b * poly.b - (4.0f * poly.a * poly.c);
	if (res.discri < 0.0f)
		return (-1.0f);
	res.t1 = (-poly.b - sqrtf(res.discri)) / (2.0f * poly.a);
	res.t2 = (-poly.b + sqrtf(res.discri)) / (2.0f * poly.a);
	res.t = fminf(res.t1, res.t2);
	ft_hit_wich_cylinder(ray, &res, obj);
	return (res.t);
}

//function that checks if the 3 objects intersect each other
void	ft_check_intersection(t_obj obj, int i, t_ray *ray)
{
	float	t_obj;

	t_obj = -1.0f;
	if (obj.id == SPHERE)
		t_obj = ft_hit_sphere(obj.pos, (obj.diameter * 0.5f), *ray);
	else if (obj.id == PLANE)
		t_obj = ft_hit_plane(obj.pos, obj.vec, *ray);
	else if (obj.id == CYLINDER)
		t_obj = ft_hit_cylinder(obj, *ray);
	if (t_obj > 0.0f)
	{
		if (ray->i_close == -1)
		{
			ray->i_close = i;
			ray->t = t_obj;
		}
		else if (t_obj < ray->t)
		{
			ray->i_close = i;
			ray->t = t_obj;
		}
	}
}

//function that checks if the shadows of the 3 objects intersect
void	ft_check_shadow_intersection(t_obj obj, int i, t_ray *ray, float t_max)
{
	float	t_obj;

	t_obj = -1.0f;
	if (obj.id == SPHERE)
		t_obj = ft_hit_sphere(obj.pos, (obj.diameter * 0.5f), *ray);
	else if (obj.id == PLANE)
		t_obj = ft_hit_plane(obj.pos, obj.vec, *ray);
	else if (obj.id == CYLINDER)
		t_obj = ft_hit_cylinder(obj, *ray);
	if (t_obj > 0.1f && t_obj < t_max + EPSILON)
	{
		if (ray->i_close == -1)
		{
			ray->i_close = i;
			ray->t = t_obj;
		}
		else if (t_obj < ray->t)
		{
			ray->i_close = i;
			ray->t = t_obj;
		}
	}
}
