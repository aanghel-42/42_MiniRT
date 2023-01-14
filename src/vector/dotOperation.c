#include "../../inc/minirt.h"

/**
 * @brief Multiply each component of a vector by a dot scalar
 * 
 * @param u The vector
 * @param dot Dot Scalar
 * 
 * @return The result
 * */
t_vec	ft_vec_multi_dot(t_vec u, double dot)
{
	t_vec	resultante;

	resultante.x = u.x * dot;
	resultante.y = u.y * dot;
	resultante.z = u.z * dot;
	return (resultante);
}

/**
 * @brief   Calculates the dot product of two vectors
 * 
 * @param   u
 * @param   v
 * 
 * @return The result
 * */
double	ft_vecdot(t_vec u, t_vec v)
{
	double	distance;

	distance = (u.x * v.x) + (u.y * v.y) + (u.z * v.z);
	return (distance);
}
