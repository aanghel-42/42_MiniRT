/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_lst.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanghel <aanghel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 18:39:33 by aanghel           #+#    #+#             */
/*   Updated: 2022/12/22 18:44:31 by aanghel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_print_lst(t_list *token)
{
	//int		i;
	t_list	*a;

	a = token;
	while (a)
	{
        //inserire i componenti della lista che si vogliono stampare
        /*
		printf("%s --- Comand\n", a->command);
		i = -1;
		while (a->value[++i] != NULL)
			printf("%s --- Value %d\n", a->value[i], i);
		printf("%s -- Token Name File\n", a->name_file);
		printf("%d -- Priority\n", a->priority);
		printf("%d -- Bool Res\n", a->res);
		printf("%d -- Bool And\n", a->and);
		printf("%d -- Bool Or\n", a->or);
		printf("%d -- Bool Pipe\n", a->pipe);
		printf("%d -- Bool Output\n", a->output);
		printf("%d -- Bool Append\n", a->append);
		printf("%d -- Bool Input\n", a->input);
		printf("%d -- Bool Heredoc\n", a->heredoc);
        */
		if (!a->next)
			break ;
		a = a->next;
	}
}