#include "../includes/utils.h"

void	ft_putstr_fd(char *s, int fd)
{
	if (s)
		if (write(fd, s, ft_strlen(s)) < 0)
			perror("");
}
