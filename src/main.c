#include "../inc/minirt.h"

int	ft_check_input(char *str)
{
	int	len;

	len = ft_strlen(str);
	if (str[len - 3] != '.' || str[len - 2] != 'r' || str[len - 1] != 't')
		return (1);
	return (0);
}

int	main(int argc, char **argv)
{
	if (argc != 2 || ft_check_input(argv[1]))
		printf("Errror in the input\n");
	return (0);
}
