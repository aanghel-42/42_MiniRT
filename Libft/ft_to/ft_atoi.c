/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanghel <aanghel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 18:55:59 by aanghel           #+#    #+#             */
/*   Updated: 2022/07/22 22:45:41 by aanghel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_atoi(const char *str)
{
	int	result;
	int	revert;
	int	n;

	result = 0;
	n = 0;
	revert = 1;
	while ((str[n] >= 9 && str[n] <= 13) || str[n] == ' ')
		n++;
	if (str[n] == '-' || str[n] == '+')
		if (str[n++] == '-')
			revert *= -1;
	result = 0;
	while (str[n] >= '0' && str[n] <= '9')
		result = result * 10 + str[n++] - '0';
	return (result * revert);
}
