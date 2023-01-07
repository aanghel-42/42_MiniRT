/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_replace_char.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcatapan <pcatapan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 01:18:21 by pcatapan          #+#    #+#             */
/*   Updated: 2023/01/07 01:25:55 by pcatapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_replace_char(char *str, char find, char replace)
{
	int		i;
	char	*rtr;

	i = 0;
	rtr = (char *)malloc(sizeof(char) * ft_strlen(str));
	while (str[i])
	{
		if (str[i] == find)
			rtr[i] = replace;
		else
			rtr[i] = str[i];
		i++;
	}
	return (rtr);
}
