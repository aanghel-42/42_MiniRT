#include "../includes/minirt.h"

//check that the chars present are not different from digits , - and .
int	ft_valid_char(char *s)
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

//check if the char respects the formatting for light ratio 
//-> (formattazione giusta: 0.2 ) -> range 0.0-1.0
int	ft_valid_char_fl(char *s)
{
	int	i;

	i = -1;
	while (s[++i])
		if (!ft_isdigit(s[i]) && (s[i] != '.'))
			return (1);
	return (0);
}

//check if the char respects the formatting for rgb 
//-> (formattazione giusta: 255,255,255) -> range 0-255
int	ft_valid_char_rgb(char *s)
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
