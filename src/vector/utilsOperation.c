#include "../../inc/minirt.h"

/**
 * @brief   Calculates the length of a vector. 
 *    Calculates the distance between the origin 
 *    and the endpoint of the vector
 * 
 * @param v
 * 
 * @return The len
 * */
double	ft_veclen(t_vec v)
{
	double	grandeur;

	grandeur = (sqrt(v.x * v.x + v.y * v.y + v.z * v.z));
	return (grandeur);
}

/**
 * @brief   Multiplies two vectors together element by element
 * 
 * @param   u
 * @param   v
 * 
 * @return The result
 * */
t_vec	ft_multi2vec_by_element(t_vec u, t_vec v)
{
	t_vec	resultante;

	resultante.x = (u.x * v.x);
	resultante.y = (u.y * v.y);
	resultante.z = (u.z * v.z);
	return (resultante);
}

/**
 * @brief   Normalize a vector to length 1 while keeping the same direction
 * 
 * @param v The vector
 * 
 * @return The result
 * */
t_vec	ft_normalize_vec(t_vec v)
{
	double	grandeur;
	t_vec	resultante;

	grandeur = sqrt((v.x * v.x) + (v.y * v.y) + (v.z * v.z));
	resultante.x = v.x / grandeur;
	resultante.y = v.y / grandeur;
	resultante.z = v.z / grandeur;
	return (resultante);
}

t_ray	ft_settings_ray(t_vec origin, t_vec direction)
{
	t_ray	ray;

	ray.origin = origin;
	ray.direction = direction;
	return (ray);
}
