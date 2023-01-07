#include "../../inc/minirt.h"

void	ft_check_content_row(char *row, t_minirt *minirt)
{
	int	i;

	i = 1;
	if (row[i] != 32)
		i++;
	while (row[i])
	{
		if (row[i] != 43 && row[i] != 44 && row[i] != 45 && row[i] != 46 \
				&& !ft_isdigit(row[i]) && row[i] != 32 && row[i] != '\n')
			ft_exit_check(NULL, minirt, "Invalid charter on file.rt\n");
		i++;
	}
}

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
		ft_exit_check(row, minirt, "Element not valid in file\n");
	return (1);
}

int	ft_parsing(t_minirt *minirt)
{
	int		i;
	char	*tmp;
	char	**rows;

	i = 0;
	while (minirt->data[i])
	{
		ft_check_content_row(minirt->data[i], minirt);
		tmp = ft_replace_char(minirt->data[i], 32, ',');
		rows = ft_split(tmp, ',');
		free(tmp);
		if (!(ft_check_type(rows, minirt)))
			return (0);
		ft_free_matrix(rows);
		i++;
	}
	return (1);
}
