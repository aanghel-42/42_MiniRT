/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanghel <aanghel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 11:58:59 by aanghel           #+#    #+#             */
/*   Updated: 2022/07/22 22:27:47 by aanghel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_read(int fd, char *str)
{
	int			result;
	char		*buf;

	result = 1;
	buf = (char *)malloc((sizeof(char)) * BUFFER_SIZE + 1);
	if (buf == NULL)
		return (NULL);
	while (!(ft_strchr(str, '\n')) && (result != 0))
	{
		result = read(fd, buf, BUFFER_SIZE);
		if (result == -1)
		{
			free(buf);
			return (NULL);
		}
		buf[result] = '\0';
		str = ft_strjoin(str, buf);
	}
	free(buf);
	return (str);
}

char	*ft_nline(char *str)
{
	int		i;
	char	*out;

	i = 0;
	if (!str[i])
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	out = (char *)malloc((sizeof(char)) * (i + 2));
	if (out == NULL)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		out[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
	{
		out[i] = str[i];
		i++;
	}
	out[i] = '\0';
	return (out);
}

char	*ft_fline(char *str)
{
	char	*fline;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (!str[i])
	{
		free(str);
		return (NULL);
	}
	fline = (char *)malloc(ft_strlen(str) - i + 1);
	if (fline == NULL)
		return (NULL);
	i++;
	while (str[i] != '\0')
		fline[j++] = str[i++];
	fline[j] = '\0';
	free(str);
	return (fline);
}

char	*get_next_line(int fd)
{
	static char		*str;
	char			*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	str = ft_read(fd, str);
	if (str == NULL)
		return (NULL);
	line = ft_nline(str);
	str = ft_fline(str);
	return (line);
}
