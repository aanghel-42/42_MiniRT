/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanghel <aanghel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 18:09:53 by aanghel           #+#    #+#             */
/*   Updated: 2023/01/07 16:41:46 by aanghel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "../Libft/libft.h"
# include <fcntl.h>
# include <math.h>
# include <mlx.h>
# include <stdbool.h>
# include "../mlx/mlx.h"

typedef struct s_a
{
	int			r;
	int			g;
	int			b;
	bool		check;
	double		light;
}	t_a;

typedef struct s_c
{
	int			fov;
	bool		check;
	double		x;
	double		y;
	double		z;
	double		vector_x;
	double		vector_y;
	double		vector_z;
}	t_c;

typedef struct s_l
{
	int			r;
	int			g;
	int			b;
	bool		check;
	double		x;
	double		y;
	double		z;
	double		bright;
}	t_l;

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

typedef struct s_minirt
{
	int			w;
	int			h;
	char		**data;
	void		*mlx_ptr;
	void		*window;
	struct s_a	*ambient;
	struct s_l	*light;
	struct s_c	*camera;
	struct s_pl	*planes;
	struct s_sp	*spheres;
	struct s_cy	*cylinders;
}	t_minirt;

// DIR Parsing
int		ft_parsing(t_minirt	*minirt);
void	ft_check_ambient(char **row, t_minirt *minirt);
void	ft_exit_check(char **row, t_minirt *minirt, char *message);
void	ft_check_light(char **row, t_minirt *minirt);
void	ft_check_camera(char **row, t_minirt *minirt);
void	ft_check_ambient(char **row, t_minirt *minirt);

//utils.c
int		ft_exit(void);

//window.c
void	ft_window(t_minirt *minirt);
#endif