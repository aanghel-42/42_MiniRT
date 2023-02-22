#include "../includes/minirt.h"

int	ft_valid_char_size(char *s)
{
	int	i;

	i = -1;
	while (s[++i])
		if (!ft_isdigit(s[i]) && (s[i] != '.'))
			return (1);
	return (0);
}

//check the size for the diameter or height
float	ft_get_size(char *size, t_main *m)
{
	if (ft_valid_char_size(size))
		exit_error_free("DIAM / HEIGHT : Invalid input\n", m->scn.obj);
	return (ft_atof(size));
}

/* checking the characters and inserting data into the info matrix */

void	ft_fill_obj_sp(char **info, t_main *m, int i)
{
	if (ft_check_size_tab(info, 4))
		exit_error_free("sp wrong nb of info\n", m->scn.obj);
	m->scn.obj[i].id = SPHERE;
	ft_get_pos(info[1], m, i);
	m->scn.obj[i].diameter = ft_get_size(info[2], m);
	ft_get_rgb(info[3], m, i);
}

void	ft_fill_obj_pl(char **info, t_main *m, int i)
{
	if (ft_check_size_tab(info, 4))
		exit_error_free("pl wrong nb of info\n", m->scn.obj);
	m->scn.obj[i].id = PLANE;
	ft_get_pos(info[1], m, i);
	ft_get_vec(info[2], m, i);
	ft_get_rgb(info[3], m, i);
}

void	ft_fill_obj_cy(char **info, t_main *m, int i)
{
	if (ft_check_size_tab(info, 6))
		exit_error_free("cy wrong nb of info\n", m->scn.obj);
	m->scn.obj[i].id = CYLINDER;
	ft_get_pos(info[1], m, i);
	ft_get_vec(info[2], m, i);
	m->scn.obj[i].diameter = ft_get_size(info[3], m);
	m->scn.obj[i].height = ft_get_size(info[4], m);
	ft_get_rgb(info[5], m, i);
}
