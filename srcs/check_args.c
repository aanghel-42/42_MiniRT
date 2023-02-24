#include "../includes/minirt.h"

/* function that return if the file have the right path
* if is a file.rt
*/
int	ft_check_type(char *name, char *type )
{
	int	n_len;
	int	t_len;
	int	start;
	int	i;

	n_len = ft_strlen(name);
	t_len = ft_strlen(type);
	start = n_len - t_len;
	i = -1;
	while (name[start] == type[++i] && name[start])
		start++;
	if (i == t_len)
		return (0);
	return (1);
}

/*
* check of args and check if the file is .rt
*/
void	ft_check_args(int argc, char **argv)
{
	if (argc != 2)
		exit_error("Wrong number of args\n");
	if (ft_check_type(argv[1], ".rt") == 1)
		exit_error("Wrong file type\n");
}
