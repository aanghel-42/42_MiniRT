#include "../../inc/minirt.h"

t_vec	ft_vec_multi_dot(t_vec u, double scalar)
{
	t_vec	resultante;

	resultante.x = u.x * scalar;
	resultante.y = u.y * scalar;
	resultante.z = u.z * scalar;
	return (resultante);
}
