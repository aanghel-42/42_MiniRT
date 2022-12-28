/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanghel <aanghel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 09:38:36 by aanghel           #+#    #+#             */
/*   Updated: 2022/07/22 22:43:23 by aanghel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strdup(const char *s1)
{
	char	*s2;
	size_t	i;
	size_t	len;

	i = 0;
	len = ft_strlen(s1) + 1;
	if (s1 == NULL)
		return (0);
	s2 = (char *)malloc(len);
	if (s2 == NULL)
		return (0);
	while (s1[i] != '\0' && i <= len)
	{
		((unsigned char *)s2)[i] = ((unsigned char *)s1)[i];
		i++;
	}
	((unsigned char *)s2)[i] = '\0';
	return (s2);
}
