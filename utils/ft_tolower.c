#include "../includes/utils.h"

int	ft_tolower(int c)
{
	if (c >= 65 && c <= 90)
		c += 32;
	return (c);
}

/*int	main()
{
	char	c = 'a';

	printf("Value before Function = %c\n", c);
	printf("Value After Function = %c\n", ft_tolower(c));
}*/
