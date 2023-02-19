#include "../includes/utils.h"

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	else
		return (0);
}

/*int main()
{
	char	c;

	c = 't';
	printf("Resultat fonction C %i\n", isdigit(c));
	printf("Resultat fonction mano %i\n", ft_isdigit(c));
}*/
