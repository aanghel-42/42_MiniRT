/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcatapan <pcatapan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/15 13:05:30 by mgarcia-          #+#    #+#             */
/*   Updated: 2023/02/19 15:38:35 by pcatapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	ft_fatal(char *message)
{
	char	error_message[100];

	ft_strcpy(error_message, "[!!] Fatal Error ");
	ft_strncat(error_message, message, 83);
	perror(error_message);
	exit(EXIT_FAILURE);
}

void	scene_error(char *message)
{
	char	error_message[100];

	ft_strcpy(error_message, "Scene Error: ");
	ft_strncat(error_message, message, 87);
	ft_putstr_fd(error_message, 2);
	exit(EXIT_FAILURE);
}

void	*ft_ec_malloc(unsigned int size)
{
	void	*ptr;

	ptr = malloc(size);
	if (ptr == NULL)
		ft_fatal("in malloc() on memory allocation");
	return (ptr);
}

void	ft_usage(char *program_name)
{
	ft_printf("Usage: %s <scene.rt>\n", program_name);
	exit(EXIT_FAILURE);
}
