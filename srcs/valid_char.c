#include "../includes/miniRT.h"

int	valid_char(char *s)
{
	int	i;

	i = -1;
	while (s[++i])
	{
		if (!i)
		{
			if (!ft_isdigit(s[i]) && s[i] != '-')
				return (1);
		}
		else
		{
			if (!ft_isdigit(s[i]) && (s[i] != '.' && s[i] != ','))
				return (1);
		}
	}
	return (0);
}

int	valid_char_fl(char *s)
{
	int	i;

	i = -1;
	while (s[++i])
		if (!ft_isdigit(s[i]) && (s[i] != '.'))
			return (1);
	return (0);
}

int	valid_char_rgb(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (!ft_isdigit(s[i]) && s[i] != ',')
			return (1);
		i++;
	}
	return (0);
}
