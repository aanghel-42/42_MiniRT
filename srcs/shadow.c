#include "../includes/minirt.h"

//function that returns the value of the shadow in the view from the cam
float	ft_shadow_value(t_ray ray, t_vec3 l_pos, t_scn scn)
{
	t_ray	shadow;
	t_vec3	hit_p;
	float	coeff;
	int		i;

	i = -1;
	coeff = 0.1f;
	hit_p = ft_vec_addition(ray.origin, ft_vec_float_multi(ray.t, ray.direction));
	shadow.origin = hit_p;
	shadow.direction = ft_normalize(ft_vec_minus(l_pos, shadow.origin));
	shadow.i_close = -1;
	while (++i < scn.n_obj)
		ft_check_shadow_intersection(scn.obj[i], i, &shadow,
			ft_distance(l_pos, hit_p));
	if (shadow.i_close == -1)
	{
		if (scn.obj[ray.i_close].id == PLANE)
			coeff = fabsf(ft_dot(ray_normal(ray, scn, hit_p), shadow.direction));
		else
			coeff = ft_dot(ray_normal(ray, scn, hit_p), shadow.direction);
		coeff *= ft_find_in_tab(&scn, 'L')->light_r;
	}
	if (coeff < ft_find_in_tab(&scn, 'A')->light_r)
		coeff = ft_find_in_tab(&scn, 'A')->light_r;
	return (coeff);
}

//function that renders the various elements in the scene
t_vec3	ft_ray_normal(t_ray ray, t_scn scn, t_vec3 hit_point)
{
	t_vec3	normal;

	normal = ft_new_vec(0.0f, 0.0f, 0.0f);
	if (scn.obj[ray.i_close].id == SPHERE)
		normal = ft_normalize(ft_vec_minus(hit_point, scn.obj[ray.i_close].pos));
	else if (scn.obj[ray.i_close].id == PLANE)
		normal = scn.obj[ray.i_close].vec;
	else if (scn.obj[ray.i_close].id == CYLINDER)
		normal = ft_cylinder_normal(&scn.obj[ray.i_close], hit_point);
	return (normal);
}

//specific function for the cylinder, in order to make it visible
t_vec3	ft_cylinder_normal(t_obj *obj, t_vec3 hit_point)
{
	t_vec3		pbis;
	t_vec3		cpoint;
	float		ax;
	float		ay;

	obj->vec = ft_normalize(obj->vec);
	if (ft_is_vec_equal(obj->vec, ft_new_vec(0.0f, 1.0f, 0.0f)))
	{
		cpoint = ft_new_vec(obj->pos.x, hit_point.y, obj->pos.z);
		return (ft_normalize(ft_vec_minus(hit_point, cpoint)));
	}
	ax = atanf(obj->vec.z / obj->vec.x) * 180.0f / M_PI;
	if (obj->vec.x < 0.0f)
		ax += 180.0f;
	ay = acosf(obj->vec.y / 1.0f) * 180.0f / M_PI;
	pbis = ft_vec_minus(hit_point, obj->pos);
	pbis = ft_rotate(pbis, 0.0f, ax, ay);
	pbis = ft_vec_addition(pbis, obj->pos);
	cpoint = ft_new_vec(obj->pos.x, obj->pos.y, obj->pos.z);
	cpoint.y = pbis.y;
	cpoint = ft_vec_minus(cpoint, obj->pos);
	cpoint = ft_rev_rotate(cpoint, 0.0f, -ax, -ay);
	cpoint = ft_vec_addition(cpoint, obj->pos);
	return (ft_normalize(ft_vec_minus(hit_point, cpoint)));
}
