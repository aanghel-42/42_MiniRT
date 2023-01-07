#include "../../inc/minirt.h"

int	ft_check_type(char **row, t_minirt *minirt)
{
	if (ft_strcmp(row[0], "A"))
		ft_check_ambient(row, minirt);
	else if (ft_strcmp(row[0], "C"))
		ft_check_camera(row, minirt);
	else if (ft_strcmp(row[0], "L"))
		ft_check_light(row, minirt);
	else if (ft_strcmp(row[0], "sp"))
		ft_check_sphere(row, minirt);
	else if (ft_strcmp(row[0], "pl"))
		ft_check_plane(row, minirt);
	else if (ft_strcmp(row[0], "cy"))
		ft_check_cylinders(row, minirt);
	else
	{
		ft_exit_check(row, minirt, "Elemet not valid in file\n");
		return (0);
	}
	return (1);
}

int	ft_parsing(t_minirt *minirt)
{
	int		i;
	char	*tmp;
	char	**row;

	i = 0;
	while (minirt->data[i])
	{
		tmp = ft_replace_char(minirt->data[i], 32, ',');
		row = ft_split(tmp, ',');
		free(tmp);
		if (!(ft_check_type(row, minirt)))
			return (0);
		ft_free_matrix(row);
		i++;
	}
	return (1);
}
