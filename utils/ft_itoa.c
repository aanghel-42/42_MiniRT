#include "../includes/utils.h"

//nbrlen voluntarily send the number of the last value inside the string

static int	nbrlen(int n, int minus)
{
	int	len;

	if (n < 10)
		len = minus;
	else
	{
		len = 0;
		while (n >= 10)
		{
			n /= 10;
			len++;
		}
		len += minus;
	}
	return (len);
}

static char	*fillerstr(int minus, char **res, int n)
{
	int		ires;

	ires = nbrlen(n, minus);
	while (ires >= (0 + minus))
	{
		(*res)[ires] = '0' + n % 10;
		n /= 10;
		ires--;
	}
	if (minus == 1)
		(*res)[ires] = '-';
	return (*res);
}

char	*ft_itoa(int n)
{
	char	*res;
	int		minus;

	minus = 0;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n < 0)
	{
		minus = 1;
		n *= -1;
	}
	res = ft_calloc((nbrlen(n, minus) + 2), sizeof(char));
	if (res == NULL)
		return (NULL);
	return (fillerstr(minus, &res, n));
}

/*int	main()
{
	printf("%s\n", ft_itoa(100));
}*/
