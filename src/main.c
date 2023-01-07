#include "../inc/minirt.h"

int	ft_check_file(char *str)
{
	int	len;

	len = ft_strlen(str);
	if (str[len - 3] != '.' || str[len - 2] != 'r' || str[len - 1] != 't')
		return (1);
	return (0);
}

char	**ft_check_content_file(char *file)
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
	return (content);
}

void	ft_init(t_minirt *minirt)
{
	minirt->ambient = (t_a *)malloc(sizeof(t_a));
	minirt->light = (t_l *)malloc(sizeof(t_l));
	minirt->camera = (t_c *)malloc(sizeof(t_c));
	minirt->ambient->check = false;
	minirt->light->check = false;
	minirt->camera->check = false;
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
	minirt->data = ft_check_content_file(argv[1]);
	if (!(ft_parsing(minirt)))
	{
		printf("Errror in the file\n");
		return (0);
	}
}
