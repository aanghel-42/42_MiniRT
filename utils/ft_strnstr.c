#include "../includes/utils.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	ihay;
	size_t	inee;
	size_t	ista;

	ihay = 0;
	if (ft_strlen(needle) == 0)
		return ((char *)haystack);
	while (haystack[ihay] != '\0' && ihay < len)
	{
		inee = 0;
		if (haystack[ihay] == needle[inee])
		{
			ista = ihay;
			while (haystack[ihay] == needle[inee] && needle[inee] != '\0')
			{
				ihay++;
				inee++;
			}
			if (needle[inee] == '\0' && ihay <= len)
				return ((char *)haystack + ista);
			ihay = ista;
		}
		ihay++;
	}
	return (NULL);
}
