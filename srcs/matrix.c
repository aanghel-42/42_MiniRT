#include "../includes/minirt.h"

/*functions for matrix calculations*/

//function that rotates the vector
t_vec3	ft_rotate(t_vec3 p, float ax, float ay, float az)
{
	float	point[3][1];
	float	m[3][3][3];

	point[0][0] = p.x;
	point[1][0] = p.y;
	point[2][0] = p.z;
	ft_get_angle_mtx(&m, ax, ay, az);
	ft_mtx_mul(m[0], point);
	ft_mtx_mul(m[1], point);
	ft_mtx_mul(m[2], point);
	p.x = point[0][0];
	p.y = point[1][0];
	p.z = point[2][0];
	return (p);
}

//function that returns to which angle the matrix must be rotated
void	ft_get_angle_mtx(float (*m)[3][3][3], float ax, float ay, float az)
{
	float	a;
	float	b;
	float	c;

	a = ax * M_PI / 180;
	b = ay * M_PI / 180;
	c = az * M_PI / 180;
	ft_mtx_setline(&(*m)[0][0], 1, 0, 0);
	ft_mtx_setline(&(*m)[0][1], 0, cosf(a), -sinf(a));
	ft_mtx_setline(&(*m)[0][2], 0, sinf(a), cosf(a));
	ft_mtx_setline(&(*m)[1][0], cosf(b), 0, sinf(b));
	ft_mtx_setline(&(*m)[1][1], 0, 1, 0);
	ft_mtx_setline(&(*m)[1][2], -sinf(b), 0, cosf(b));
	ft_mtx_setline(&(*m)[2][0], cosf(c), -sinf(c), 0);
	ft_mtx_setline(&(*m)[2][1], sinf(c), cosf(c), 0);
	ft_mtx_setline(&(*m)[2][2], 0, 0, 1);
}

//function that sets the elements in the line of the matrix
void	ft_mtx_setline(float (*line)[], float a, float b, float c)
{
	(*line)[0] = a;
	(*line)[1] = b;
	(*line)[2] = c;
}

//function that multiplies two matrices together
void	ft_mtx_mul(float a[3][3], float b[3][1])
{
	int		i;
	int		j;
	int		k;
	float	res[3][1];

	i = 0;
	while (i < 3)
	{
		j = 0;
		while (j < 1)
		{
			k = 0;
			res[i][j] = 0;
			while (k < 3)
			{
				res[i][j] += a[i][k] * b[k][j];
				k++;
			}
			j++;
		}
		i++;
	}
	b[0][0] = res[0][0];
	b[1][0] = res[1][0];
	b[2][0] = res[2][0];
}

//function that revert the rotates the vector
t_vec3	ft_rev_rotate(t_vec3 p, float ax, float ay, float az)
{
	float	point[3][1];
	float	m[3][3][3];

	point[0][0] = p.x;
	point[1][0] = p.y;
	point[2][0] = p.z;
	ft_get_angle_mtx(&m, ax, ay, az);
	ft_mtx_mul(m[2], point);
	ft_mtx_mul(m[1], point);
	ft_mtx_mul(m[0], point);
	p.x = point[0][0];
	p.y = point[1][0];
	p.z = point[2][0];
	return (p);
}
