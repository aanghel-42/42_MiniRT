#include "../includes/utils.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	res;
	int	minus;

	minus = 1;
	i = 0;
	res = 0;
	while ((str[i] > 8 && str[i] < 14) || str[i] == ' ')
		i++;
	if (str[i] == '-')
	{
		minus = -1;
		i++;
	}
	if (str[i] == '+' && minus == 1)
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = (res * 10) + str[i] - '0';
		i++;
	}
	return (res * minus);
}
