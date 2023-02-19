#include "../includes/utils.h"

int	ft_strcmp_case(const char *s1, const char *s2)
{
	int	idx;

	if (!s1)
		return (-1);
	idx = 0;
	while (s1[idx] != '\0' && s2[idx] != '\0')
	{
		if (s1[idx] != s2[idx])
		{
			if (!(s1[idx] - s2[idx] == 32 || s2[idx] - s1[idx] == 32))
				return ((unsigned char)s1[idx] - (unsigned char)s2[idx]);
		}
		idx++;
	}
	if (s1[idx] == '\0' || s2[idx] == '\0')
		return ((unsigned char)s1[idx] - (unsigned char)s2[idx]);
	return (0);
}
