
#ifndef MINIRT_H
# define MINIRT_H

# include "../Libft/libft.h"
# include <fcntl.h>
# include <math.h>
# include <mlx.h>
# include <stdbool.h>
# include "../mlx/mlx.h"

# define WIDTH	1080
# define HEIGHT 720
# define KEY_ESC 53
# define M_INFINITY 1.0e30f

typedef struct s_vector
{
	double	x;
	double	y;
	double	z;
}	t_vec;

typedef struct s_ray
{
	t_vec	origin;
	t_vec	direction;	
}	t_ray;

typedef struct s_rgb
{
	int	r;
	int	g;
	int	b;
}	t_rgb;

typedef struct s_a
{
	t_rgb		rgb;
	bool		check;
	double		light;
}	t_a;

typedef struct s_c
{
	int			fov;
	bool		check;
	t_vec		cor;
	t_vec		vec;
}	t_c;

typedef struct s_l
{
	t_rgb		rgb;
	bool		check;
	t_vec		cor;
	double		bright;
}	t_l;

typedef struct s_sp
{
	t_rgb		rgb;
	bool		check;
	t_vec		cor;
	double		diameter;
	struct s_sp	*next;
	struct s_sp	*prev;
}	t_sp;

typedef struct s_pl
{
	t_rgb		rgb;
	bool		check;
	t_vec		cor;
	t_vec		vec;
	struct s_pl	*next;
	struct s_pl	*prev;
}	t_pl;

typedef struct s_cy
{
	t_rgb		rgb;
	bool		check;
	t_vec		cor;
	t_vec		vec;
	double		diameter;
	double		height;
	struct s_cy	*next;
	struct s_cy	*prev;
}	t_cy;

typedef struct s_quadra
{
	double	a;
	double	b;
	double	c;
	double	t;
	double	t1;
}	t_quadra;

typedef struct s_mlx
{
	int		w;
	int		h;
	int		bpp;
	int		endian;
	int		w_len;
	char	*addr;
	void	*mlx_ptr;
	void	*window;
	void	*img;
}	t_mlx;

typedef struct s_minirt
{
	char			**data;
	void			*mlx_ptr;
	struct s_a		*ambient;
	struct s_l		*light;
	struct s_c		*camera;
	struct s_pl		*planes;
	struct s_sp		*spheres;
	struct s_cy		*cylinders;
	struct s_mlx	*mlx;
}	t_minirt;

// DIR Parsing
int		ft_parsing(t_minirt	*minirt);
void	ft_check_ambient(char **row, t_minirt *minirt);
void	ft_check_light(char **row, t_minirt *minirt);
void	ft_check_camera(char **row, t_minirt *minirt);
void	ft_check_ambient(char **row, t_minirt *minirt);
void	ft_check_cylinders(char **row, t_minirt *minirt);
void	ft_check_plane(char **row, t_minirt *minirt);
void	ft_check_sphere(char **row, t_minirt *minirt);

// DIR Free
int		ft_exit(t_minirt *minirt);
void	ft_free_cy(t_cy *elements);
void	ft_free_sp(t_sp *elements);
void	ft_free_pl(t_pl *elements);
void	ft_exit_check(char **row, t_minirt *minirt, char *message);

// DIR Shape
t_cy	*ft_rtr_head_cy(t_cy *cy);
t_pl	*ft_rtr_head_pl(t_pl *pl);
t_sp	*ft_rtr_head_sp(t_sp *sp);
t_sp	*ft_init_sp(t_sp	*sp);
t_sp	*ft_lstadd_back_sp(t_sp *lst, t_sp *new);
t_sp	*ft_lstnew_sp(t_sp *sp);
t_pl	*ft_lstadd_back_pl(t_pl *lst, t_pl *new);
t_pl	*ft_lstnew_pl(t_pl *pl);
t_cy	*ft_lstadd_back_cy(t_cy *lst, t_cy *new);
t_cy	*ft_lstnew_cy(t_cy *cy);
double	ft_hit_cylinder(t_cy *cyl, t_vec r_o, t_vec rd);
double	ft_hit_plane(t_pl *pl, t_vec r_o, t_vec rd);
double	ft_hit_sphere(t_sp *sp, t_vec ro, t_vec rd);
int		ft_get_color_sp(t_minirt *minirt, int color, double closer, t_ray *ray);
int		ft_get_color_cy(t_minirt *minirt, int color, double closer, t_ray *ray);
int		ft_get_color_pl(t_minirt *minirt, int color, double closer, t_ray *ray);

// DIR Render
double	ft_calc_root_cy(double top_relor, double toprd, double h_2, double t);
double	ft_get_root(double disc, double b);

// utils.c
void	ft_return_head(t_minirt *minirt);

//mlx_utils.c
int		ft_key(int key, t_minirt *minirt);
void	ft_init_mlx(t_mlx *mlx);

// Print_lst.c
void	ft_print_lst_ambient(t_a *token);
void	ft_print_spheres(t_sp *spehres);
void	ft_print_planes(t_pl *planes);
void	ft_print_cylinders(t_cy *cylinders);

// DIR Vector
t_vec	ft_new_vector(double x, double y, double z);
t_vec	ft_subvec(t_vec u, t_vec v);
t_vec	ft_normalize_vec(t_vec v);
t_ray	ft_settings_ray(t_vec origin, t_vec direction);
t_vec	ft_vec_multi_dot(t_vec u, double dot);
double	ft_vecdot(t_vec u, t_vec v);

//DIR Scene
void	ft_create_scene(t_minirt *minirt);
t_ray	ray_generator(t_minirt *minirt, int x, int y);

#endif