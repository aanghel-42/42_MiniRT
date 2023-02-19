#include "../includes/utils.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != (char)c && s[i] != '\0')
		i++;
	if (s[i] == (char)c)
		return ((char *) s + i);
	else
		return (NULL);
}

/*int	main()
{
	char s[] = "tripouille";

	printf("Value Fonction C = %s\n", strchr(s, 't' + 256));
	printf("Value Fonction Mano = %s\n", ft_strchr(s, 't' + 256));
}*/
