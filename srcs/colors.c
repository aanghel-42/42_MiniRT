#include "../includes/minirt.h"

int	ft_create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

/* 
* function that inserts the various rgb within the single
* pixels with ft_mlx_pixel_put
*/
void	ft_put_pixel_color(t_mlx *mlx, int x, int y, t_vec3 rgb)
{
	ft_mlx_pixel_put(&mlx->img, x, y, ft_create_trgb(0, rgb.x * 255, \
		rgb.y * 255, rgb.z * 255));
}
