/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanghel <aanghel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 09:22:28 by aanghel           #+#    #+#             */
/*   Updated: 2022/07/22 22:40:53 by aanghel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t	len;
	void	*str;

	len = count * size;
	str = malloc(len);
	if (str == NULL)
		return (0);
	ft_bzero(str, len);
	return (str);
}
