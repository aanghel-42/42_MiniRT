/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcatapan <pcatapan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 21:34:09 by pcatapan          #+#    #+#             */
/*   Updated: 2023/01/06 22:31:55 by pcatapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/**
 * @brief Search needle in haystack
 * 
 * @param haystack Str in which to search
 * @param needle Str to serch
 * 
 * @return 0 if don't find the needle. 1 if find the needle
 */
int	ft_strstr(char *haystack, char *needle)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (!haystack || !needle)
		return (0);
	if (needle[0] == '\0')
		return (0);
	while (haystack[i])
	{
		j = 0;
		if (needle[j] == haystack[i])
		{
			while (needle[j] == haystack[i + j] && needle[j])
				j++;
			if (!needle[j])
				return (1);
		}
		i++;
	}
	return (0);
}
