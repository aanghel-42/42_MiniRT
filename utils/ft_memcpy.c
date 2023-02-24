#include "../includes/utils.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if (dst == src || n == 0)
		return (dst);
	while (i < n)
	{
		*((char *)dst + i) = *((char *)src + i);
		i++;
	}
	return (dst);
}
