/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcatapan <pcatapan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 16:21:09 by pcatapan          #+#    #+#             */
/*   Updated: 2023/01/07 16:36:44 by pcatapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include <math.h>

/**
 * @brief Convert a str in double
 * 
 * @param str String to convert
 * */
double	ft_atof(const char *str)
{
	double	int_part;
	double	dec_part;
	double	sign;
	int		i;
	int		dec;

	int_part = 0.0;
	dec_part = 0.0;
	sign = 1.0;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '+' || str[i] == '-')
		if (str[i++] == '-')
			sign = -1.0;
	while (ft_isdigit(str[i]))
		int_part = int_part * 10 + (str[i++] - '0');
	dec = -1;
	if (str[i] == '.' && str[i++])
	{
		while (ft_isdigit(str[i]))
			dec_part += (pow(10, dec--) * (str[i++] - '0'));
	}
	return (sign * (int_part + dec_part));
}
