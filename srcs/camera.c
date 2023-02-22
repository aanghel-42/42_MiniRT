#include "../includes/minirt.h"

//search element on the scn struct
t_obj	*ft_find_in_tab(t_scn *scn, int id)
{
	int	i;

	i = 0;
	while (i < scn->n_obj)
	{
		if (scn->obj[i].id == id)
			break ;
		i++;
	}
	return (&scn->obj[i]);
}

//initialization the cam struct
void	ft_camera_init(t_mlx *mlx, t_camera *cam, t_scn *scn)
{
	t_obj	*cam_info;

	cam_info = ft_find_in_tab(scn, 'C');
	cam->fov = cam_info->fov;
	cam->pos = cam_info->pos;
	cam->dir = cam_info->vec;
	cam->forward = ft_normalize(cam->dir);
	cam->right = ft_cross(ft_new_vec(0.0f, -1.0f, 0.0f), cam->forward);
	cam->right = ft_normalize(cam->right);
	cam->up = ft_vec_float_multi(-1.0f, ft_cross(cam->forward, cam->right));
	cam->w = (float)fabs(tan(cam->fov));
	cam->h = cam->w * mlx->aspect_ratio;
}

void	ft_camera_update(t_main *main)
{
	main->cam.forward = ft_normalize(main->cam.dir);
	main->cam.right = ft_cross(ft_new_vec(0.0f, -1.0f, 0.0f), main->cam.forward);
	main->cam.right = ft_normalize(main->cam.right);
	main->cam.up = ft_vec_float_multi(-1.0f, \
		ft_cross(main->cam.forward, main->cam.right));
}
