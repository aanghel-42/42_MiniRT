/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanghel <aanghel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 18:09:53 by aanghel           #+#    #+#             */
/*   Updated: 2022/12/28 18:46:32 by aanghel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MIINIRT_H

# include "./MLX42/include/MLX42/MLX*.h"
# include "./Libft/libft.h"
# include <math.h>

typedef struct s_a
{
	int			r;
	int			g;
	int			b;
	double		light;
	struct s_a	*next;
}	t_a;

typedef struct s_l
{
	int			r;
	int			g;
	int			b;
	double		x;
	double		y;
	double		z;
	double		bright;
	struct s_l	*next;
}	t_l;

typedef struct s_c
{
	int			fov;
	double		x;
	double		y;
	double		z;
	double		vector_x;
	double		vector_y;
	double		vector_z;
	struct s_c	*next;
}	t_c;

typedef struct s_pl
{
	int			r;
	int			g;
	int			b;
	double		x;
	double		y;
	double		z;
	double		vector_x;
	double		vector_y;
	double		vector_z;
	struct s_pl	*next;
}	t_pl;

typedef struct s_sp
{
	int			r;
	int			g;
	int			b;
	double		x;
	double		y;
	double		z;
	double		diameter;
	struct s_sp	*next;
}	t_sp;

typedef struct s_cy
{
	int			r;
	int			g;
	int			b;
	double		x;
	double		y;
	double		z;
	double		vector_x;
	double		vector_y;
	double		vector_z;
	double		diameter;
	double		height;
	struct s_cy	*next;
}	t_cy;