#include "../includes/miniRT.h"

void	free_split_exit(char **split, t_obj *obj, char *str)
{
	ft_tab_free((void **)split);
	exit_error_free(str, obj);
}

void	exit_error(char *str)
{
	printf("\033[31m%s", str);
	exit(EXIT_FAILURE);
}

void	exit_error_free(char *str, t_obj *ptr)
{
	if (ptr)
		free(ptr);
	exit_error(str);
}

void	perror_exit(char *s)
{
	perror(s);
	exit(EXIT_FAILURE);
}
