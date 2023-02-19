#include "../includes/utils.h"

void	ft_mem_alloc_check(void *ptr)
{
	if (ptr == NULL)
	{
		free(ptr);
		ft_putendl_fd("Error, dynamic allocation failed", 2);
		exit(EXIT_FAILURE);
	}
}
