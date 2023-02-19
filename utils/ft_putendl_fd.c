#include "../includes/utils.h"

void	ft_putendl_fd(char *s, int fd)
{
	int		idx;
	char	nl;

	nl = '\n';
	idx = 0;
	if (s != NULL)
	{
		while (s[idx] != '\0')
		{
			write(fd, s + idx, 1);
			idx++;
		}
		write(fd, &nl, 1);
	}
}
