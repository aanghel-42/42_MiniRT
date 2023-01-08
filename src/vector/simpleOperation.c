#include "../../inc/minirt.h"

/**
 * @brief Create new vector
 * 
 * @return Vector
 * */
t_vec	ft_new_vector(double x, double y, double z)
{
	t_vec	vector;

	vector.x = x;
	vector.y = y;
	vector.z = z;
	return (vector);
}

/**
 * @brief Add two vectors
 * 
 * @param u vectors one
 * @param v vectors two
 * 
 * @return The result
 * */
t_vec	ft_add_vec(t_vec u, t_vec v)
{
	t_vec	resultante;

	resultante.x = u.x + v.x;
	resultante.y = u.y + v.y;
	resultante.z = u.z + v.z;
	return (resultante);
}

/**
 * @brief Subtraction of two vectors
 * 
 * @param u vectors one
 * @param v vectors two
 * 
 * @return The result
 * */
t_vec	ft_sub_vec(t_vec u, t_vec v)
{
	t_vec	resultante;

	resultante.x = u.x - v.x;
	resultante.y = u.y - v.y;
	resultante.z = u.z - v.z;
	return (resultante);
}
