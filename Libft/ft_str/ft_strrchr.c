/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcatapan <pcatapan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 18:42:17 by aanghel           #+#    #+#             */
/*   Updated: 2023/01/06 22:37:48 by pcatapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*pos;

	pos = NULL;
	while (*s)
	{
		if (*s == (char)c)
			pos = ((char *)s);
		s++;
	}
	if ((char)c == '\0')
		return ((char *)s);
	return (pos);
}
