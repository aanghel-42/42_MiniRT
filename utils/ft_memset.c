#include "../includes/utils.h"

void	*ft_memset(void *b, int c, size_t len)
{
	int	ib;

	ib = 0;
	while (len-- > 0)
		((char *)b)[ib++] = c;
	return (b);
}
