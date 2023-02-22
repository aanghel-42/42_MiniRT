#include "../includes/minirt.h"

/*mathematical functions for the calculation of vectors*/

//function that returns the length of the vector
float	ft_vec_length(t_vec3 vec)
{
	float	res;

	res = sqrtf((vec.x * vec.x) + (vec.y * vec.y) + (vec.z * vec.z));
	return (res);
}

//function that returns the normalization of a vector
t_vec3	ft_normalize(t_vec3 vec)
{
	t_vec3	new_vec;
	float	k;

	k = 1.0f / ft_vec_length(vec);
	new_vec.x = vec.x * k;
	new_vec.y = vec.y * k;
	new_vec.z = vec.z * k;
	return (new_vec);
}

//function that returns the addition of vectors
t_vec3	ft_vec_addition(t_vec3 lhs, t_vec3 rhs)
{
	t_vec3	res;

	res.x = rhs.x + lhs.x;
	res.y = rhs.y + lhs.y;
	res.z = rhs.z + lhs.z;
	return (res);
}

//function that returns the multiplication between vectors
t_vec3	ft_vec_multiplication(t_vec3 lhs, t_vec3 rhs)
{
	t_vec3	res;

	res.x = rhs.x * lhs.x;
	res.y = rhs.y * lhs.y;
	res.z = rhs.z * lhs.z;
	return (res);
}

//function that returns the multiplication of the vector by a value
t_vec3	ft_vec_float_multi(float m, t_vec3 vec)
{
	t_vec3	res;

	res.x = m * vec.x;
	res.y = m * vec.y;
	res.z = m * vec.z;
	return (res);
}
