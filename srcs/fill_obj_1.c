#include "../includes/minirt.h"

/* checking the characters and inserting data into the info matrix */

void	ft_fill_obj_a(char **info, t_main *m, int i)
{
	if (ft_check_size_tab(info, 3))
		exit_error_free("A wrong nb of info\n", m->scn.obj);
	if (m->scn.a)
		exit_error_free("A already appeared in file\n", m->scn.obj);
	m->scn.obj[i].id = 'A';
	ft_get_l_r(info[1], m, i);
	ft_get_rgb(info[2], m, i);
	m->scn.a++;
}

void	ft_fill_obj_c(char **info, t_main *m, int i)
{
	if (ft_check_size_tab(info, 4))
		exit_error_free("C wrong nb of info\n", m->scn.obj);
	if (m->scn.c)
		exit_error_free("C already appeared in file\n", m->scn.obj);
	m->scn.obj[i].id = 'C';
	ft_get_pos(info[1], m, i);
	ft_get_vec(info[2], m, i);
	ft_get_fov(info[3], m, i);
	m->scn.c++;
}

void	ft_fill_obj_l(char **info, t_main *m, int i)
{
	if (ft_check_size_tab(info, 3))
		exit_error_free("L wrong nb of info\n", m->scn.obj);
	if (m->scn.l)
		exit_error_free("L already appeared in file\n", m->scn.obj);
	m->scn.obj[i].id = 'L';
	ft_get_pos(info[1], m, i);
	ft_get_l_r(info[2], m, i);
	m->scn.l++;
}
