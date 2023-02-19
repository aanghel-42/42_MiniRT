#include "../includes/utils.h"

void	*ft_bzero(void *s, size_t n)
{
	int	is;

	is = 0;
	while (n-- > 0)
		((char *)s)[is++] = '\0';
	return (s);
}

