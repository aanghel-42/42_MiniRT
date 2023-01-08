#include "../inc/minirt.h"

void	ft_init_mlx(t_mlx *mlx)
{
	mlx->mlx_ptr = mlx_init();
	mlx->w = WIDTH;
	mlx->h = HEIGHT;
	mlx->img = mlx_new_image(mlx->mlx_ptr, mlx->w, mlx->h);
	mlx->addr = mlx_get_data_addr(mlx->img, &mlx->bpp, \
		&mlx->w_len, &mlx->endian);
	mlx->window = mlx_new_window(mlx->mlx_ptr, mlx->w, mlx->h, "MiniRT");
}

int	ft_key(int key, t_minirt *minirt)
{
	if (key == KEY_ESC)
		ft_exit(minirt);
	return (0);
}
