#include "../includes/minirt.h"

char	*ft_trim_free(char *s, char *set)
{
	char	*tmp;

	tmp = ft_strtrim(s, set);
	free(s);
	return (tmp);
}

int	ft_check_size_tab(char **str, int nb)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	if (i != nb)
		return (1);
	return (0);
}

//function opens and reads the file with gnl and counts the objects present
void	ft_count_obj(char *f_path, t_main *m)
{
	int		fd;
	char	*line;

	fd = open(f_path, O_RDONLY);
	if (fd == -1)
		perror_exit("Problem opening file");
	line = get_next_line(fd);
	if (!line)
		exit_error("File empty\n");
	while (line)
	{
		if (line && ft_strcmp_case(line, "\n"))
			m->scn.n_obj++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
}

float	ft_atof(char *s)
{
	int		sign;
	float	res;
	float	dec;
	int		i;
	int		j;

	i = 0;
	sign = 1;
	res = 0;
	dec = 0;
	if (s[i] == '-')
	{
		sign *= -1;
		i++;
	}
	while (s[i] && s[i] != '.')
		res = (res * 10) + (s[i++] - '0');
	if (s[i++] == '.')
	{
		j = ft_strlen(s) - i;
		while (s[i])
			dec = (dec * 10) + (s[i++] - '0');
		res = res + (dec / pow(10, j));
	}
	return (res * sign);
}
