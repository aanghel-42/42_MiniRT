#include "../inc/minirt.h"

int	ft_check_file(char *str)
{
	int	len;

	len = ft_strlen(str);
	if (str[len - 3] != '.' || str[len - 2] != 'r' || str[len - 1] != 't')
		return (1);
	return (0);
}

char	**ft_get_content_file(char *file)
{
	int		fd;
	int		i;
	char	**content;

	fd = open(file, 'r');
	i = 0;
	content = (char **)malloc(sizeof(char));
	content[0] = NULL;
	while (1)
	{
		content[i] = get_next_line(fd);
		if (!content[i])
			break ;
		i++;
	}
	close(fd);
	return (content);
}

void	ft_init(t_minirt *minirt)
{
	minirt->ambient = (t_a *)malloc(sizeof(t_a));
	minirt->light = (t_l *)malloc(sizeof(t_l));
	minirt->camera = (t_c *)malloc(sizeof(t_c));
	minirt->planes = (t_pl *)malloc(sizeof(t_pl));
	minirt->spheres = (t_sp *)malloc(sizeof(t_sp));
	minirt->cylinders = (t_cy *)malloc(sizeof(t_cy));
	minirt->ambient->check = false;
	minirt->light->check = false;
	minirt->camera->check = false;
	minirt->data = NULL;
}

int	main(int argc, char **argv)
{
	t_minirt	*minirt;

	minirt = (t_minirt *)malloc(sizeof(t_minirt));
	if (argc != 2 || ft_check_file(argv[1]))
	{
		printf("Errror in the input\n");
		return (0);
	}
	ft_init(minirt);
	minirt->data = ft_get_content_file(argv[1]);
	if (!(ft_parsing(minirt)))
		return (0);
	ft_exit_check(NULL, minirt, NULL);
	//ft_print_lst_ambient(minirt->ambient);
}
