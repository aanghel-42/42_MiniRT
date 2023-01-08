#include "../../inc/minirt.h"

void	ft_exit_check(char **row, t_minirt *minirt, char *message)
{
	if (row)
		ft_free_matrix(row);
	if (minirt)
	{
		free(minirt->ambient);
		free(minirt->camera);
		free(minirt->light);
		ft_free_pl(minirt->planes);
		ft_free_sp(minirt->spheres);
		ft_free_cy(minirt->cylinders);
		free(minirt->mlx);
		if (minirt->data)
			ft_free_matrix(minirt->data);
		free(minirt);
	}
	if (message)
		printf("%s", message);
	exit(0);
}

int	ft_exit(t_minirt *minirt)
{
	mlx_destroy_image(minirt->mlx->mlx_ptr, minirt->mlx->img);
	mlx_destroy_window(minirt->mlx->mlx_ptr, minirt->mlx->window);
	ft_exit_check(NULL, minirt, NULL);
	exit(0);
	return (0);
}
