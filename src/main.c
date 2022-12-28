/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcatapan <pcatapan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 18:09:45 by pcatapan          #+#    #+#             */
/*   Updated: 2022/12/28 19:08:37 by pcatapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

int	ft_check_input(char *str)
{
	int	len;

	len = ft_strlen(str);
	if (str[len - 2] != '.' || str[len - 1] != 'r' || str[len] != 't')
		return (1);
	return (0);
}

int	main(int argc, char **argv)
{
	if (ft_check_input(argv[1]) && argc == 2)
		printf("Errror in the input\n");
}
