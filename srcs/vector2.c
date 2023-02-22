#include "../includes/minirt.h"

/*mathematical functions for the calculation of vectors*/

//function that returns a new vector
t_vec3	new_vec(float x, float y, float z)
{
	t_vec3	new;

	new.x = x;
	new.y = y;
	new.z = z;
	return (new);
}

//function that returns the dot product of two vectors
//dot -> prodotto scalare tra due vettori
float	dot(t_vec3 lhs, t_vec3 rhs)
{
	float	res;

	res = (rhs.x * lhs.x) + (rhs.y * lhs.y) + (rhs.z * lhs.z);
	return (res);
}

//function that returns the subtraction of two vectors
t_vec3	vec_minus(t_vec3 lhs, t_vec3 rhs)
{
	t_vec3	res;

	res.x = lhs.x - rhs.x;
	res.y = lhs.y - rhs.y;
	res.z = lhs.z - rhs.z;
	return (res);
}

//function that returns the cross product of the vector
//cross -> prodotto vettoriale tra due vettori
t_vec3	cross(t_vec3 lhs, t_vec3 rhs)
{
	t_vec3	res;

	res.x = (lhs.y * rhs.z) - (lhs.z * rhs.y);
	res.y = (lhs.z * rhs.x) - (lhs.x * rhs.z);
	res.z = (lhs.x * rhs.y) - (lhs.y * rhs.x);
	return (res);
}

//function that returns the length of the vector
t_vec3	vec_div(float div, t_vec3 vec)
{
	float	k;

	k = 1.0f / div;
	vec.x *= k;
	vec.y *= k;
	vec.z *= k;
	return (vec);
}
