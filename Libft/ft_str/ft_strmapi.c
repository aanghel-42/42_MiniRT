/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanghel <aanghel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 15:13:17 by aanghel           #+#    #+#             */
/*   Updated: 2022/07/22 22:45:00 by aanghel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	counter;
	char			*new_str;

	if (s == 0 || (*f) == 0)
		return (0);
	counter = 0;
	new_str = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!new_str)
		return (0);
	while (s[counter])
	{
		new_str[counter] = (*f)(counter, s[counter]);
		counter++;
	}
	new_str[counter] = '\0';
	return (new_str);
}
