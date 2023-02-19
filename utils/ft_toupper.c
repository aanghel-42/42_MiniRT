#include "../includes/utils.h"

int	ft_toupper(int c)
{
	if (c >= 97 && c <= 122)
		c -= 32;
	return (c);
}

/*int	main()
{
	char	c = ' ';

	printf("Char before Function = %c\n", c);
	printf("Char after Function = %c\n", ft_toupper(c));
}*/
