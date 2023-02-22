#include "../includes/minirt.h"

int	main(int argc, char **argv)
{
	t_main	m;

	ft_parse(argc, argv, &m);
	ft_rt_init(&m.mlx);
	ft_camera_init(&m.mlx, &m.cam, &m.scn);
	mlx_hook(m.mlx.window, 2, (1L << 13), ft_keyhook, &m);
	mlx_hook(m.mlx.window, 17, 0, ft_close_window, &m);
	ft_frame_loop(&m);
	mlx_loop(m.mlx.ptr);
	return (0);
}
