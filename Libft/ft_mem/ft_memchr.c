/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanghel <aanghel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 18:59:50 by aanghel           #+#    #+#             */
/*   Updated: 2022/07/22 22:40:56 by aanghel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*t1;
	unsigned int		i;

	i = 0;
	t1 = (unsigned char *)s;
	while (i < n)
	{
		if (t1[i] == (unsigned char)c)
			return ((void *) &t1[i]);
		i++;
	}
	return (NULL);
}
