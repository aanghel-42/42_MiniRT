/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcatapan <pcatapan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 19:11:38 by pcatapan          #+#    #+#             */
/*   Updated: 2023/01/07 16:02:46 by pcatapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strjoin_gnl(char *s1, char *s2)
{
	char	*str;
	int		i;
	int		c;

	if (!s1 || !s2)
		return (NULL);
	str = (char *)malloc(sizeof(char)
			* (ft_strlen((char *)s1) + ft_strlen((char *)s2) + 1));
	if (str == NULL)
		return (0);
	i = 0;
	c = 0;
	while (s1[c] != '\0')
	{
		str[c] = s1[c];
		c++;
	}
	while (s2[i] != '\0')
		str[c++] = s2[i++];
	str[c] = '\0';
	free(s1);
	return (str);
}

char	*ft_n_line(char *save)
{
	int		i;
	int		j;
	char	*nline;

	i = 0;
	while (save[i] && save[i] != '\n')
		i++;
	if (!save[i])
	{
		free(save);
		return (NULL);
	}
	nline = (char *)malloc(sizeof(char) * (ft_strlen(save) - i + 1));
	if (!nline)
	{
		free(save);
		return (NULL);
	}
	i++;
	j = 0;
	while (save[i] != '\0')
		nline[j++] = save[i++];
	nline[j] = '\0';
	free(save);
	return (nline);
}

char	*ft_p_line(char *save)
{
	char	*line;
	int		i;

	i = 0;
	if (!save[i])
		return (NULL);
	while (save[i] && save[i] != '\n')
		i++;
	line = (char *)malloc(sizeof(char) * (i + 2));
	if (!line)
		return (NULL);
	i = 0;
	while (save[i] && save[i] != '\n')
	{
		line[i] = save[i];
		i++;
	}
	if (save[i] == '\n')
	{
		line[i] = save[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*ft_reads(char *save, int fd)
{
	char	*buffer;
	int		n;

	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	n = 1;
	while (!ft_strchr(save, '\n') && n != 0)
	{
		n = read(fd, buffer, BUFFER_SIZE);
		if (n == -1)
		{
			free(buffer);
			free(save);
			return (NULL);
		}
		buffer[n] = '\0';
		save = ft_strjoin_gnl(save, buffer);
	}
	free(buffer);
	return (save);
}

char	*get_next_line(int fd)
{
	static char	*save;
	char		*line;

	if (fd < 0)
		return (NULL);
	if (!save)
	{
		save = (char *)malloc(sizeof(char) * 1);
		if (!save)
			return (NULL);
		save[0] = '\0';
	}
	save = ft_reads(save, fd);
	if (!save)
		return (NULL);
	line = ft_p_line(save);
	save = ft_n_line(save);
	return (line);
}
