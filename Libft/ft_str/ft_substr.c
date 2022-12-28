/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanghel <aanghel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 13:54:05 by aanghel           #+#    #+#             */
/*   Updated: 2022/07/22 22:45:30 by aanghel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	char			*sub;
	unsigned int	j;

	j = (unsigned int)len;
	i = 0;
	if (s == NULL)
		return (NULL);
	if (ft_strlen(s) <= len)
		sub = (char *)malloc((ft_strlen(s) + 1));
	else
		sub = (char *)malloc((j + 1));
	if (sub == NULL)
		return (NULL);
	if (!(start > (unsigned int)ft_strlen(s)))
	{
		while (i < j && s[start] != '\0')
			sub[i++] = s[start++];
	}
	sub[i] = '\0';
	return (sub);
}
