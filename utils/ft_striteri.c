#include "../includes/utils.h"

void	ft_striteri(char *s, void (*f) (unsigned int, char*))
{
	size_t	idx;

	idx = 0;
	if (s != NULL)
	{
		while (idx < ft_strlen(s))
		{
			f(idx, s + idx);
			idx++;
		}
	}
}
