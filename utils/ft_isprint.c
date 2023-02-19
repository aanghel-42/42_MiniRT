#include "../includes/utils.h"

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (1);
	else
		return (0);
}

/*int main()
{
	char	c;

	c = 127;
	printf("Fonction C = %i\n", isprint(c));
	printf("Fonction mano = %i\n", ft_isprint(c));
}*/
