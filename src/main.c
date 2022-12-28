/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcatapan <pcatapan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 18:09:45 by pcatapan          #+#    #+#             */
/*   Updated: 2022/12/28 18:46:16 by pcatapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "./minirt.h"

int	ft_check_input(char **str)
{
	int	len;

	len = ft_strlen(str);
	if (str[1][len - 2] != "." || str[1][len - 1] != "r" || str[1][len] != "t")
		return (1);
	return (0);
}

int	main(int argv, char **argc)
{
	if (ft_check_input(argc) && argv == 2)
		printf("Errror in the input\n");
}
