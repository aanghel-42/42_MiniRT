#include "../includes/utils.h"

// Itoa base only works for base different than 10
// For base 10 use the regular Itoa

static int	nbrlen(unsigned long n, unsigned int tbase)
{
	int	len;

	len = 0;
	if (n < tbase)
		len = 0;
	else
	{
		while (n >= tbase)
		{
			n /= tbase;
			len++;
		}
	}
	return (len);
}

static	void	*fillerstr(char **res, unsigned long n, int tbase)
{
	int		ires;

	ires = nbrlen(n, tbase);
	while (ires >= 0)
	{
		(*res)[ires] = '0' + n % tbase;
		n /= tbase;
		ires--;
	}
	return (NULL);
}

void	*check_base(char **res, char const *base)
{
	int	ires;
	int	ibase;

	ires = 0;
	while ((*res)[ires])
	{
		if ((*res)[ires] <= '9')
			ires++;
		else
		{
			ibase = ((*res)[ires] - '9') + 9;
			(*res)[ires] = base[ibase];
			ires++;
		}
	}
	return (NULL);
}

void	*ft_itoa_base(char **res, unsigned long n, char const *base)
{
	int		tbase;

	tbase = ft_strlen(base);
	*res = ft_calloc((nbrlen(n, tbase) + 2), sizeof(char));
	if (*res == NULL)
		return (NULL);
	fillerstr(res, n, tbase);
	check_base(res, base);
	return (NULL);
}
