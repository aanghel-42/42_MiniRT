#include "../../inc/minirt.h"

t_cy	*ft_rtr_head_cy(t_cy *cy)
{
	while (cy)
	{
		if (!cy->prev)
			break ;
		cy = cy->prev;
	}
	return (cy);
}


t_cy	*ft_lstnew_cy(t_cy *cy)
{
	t_cy	*token;

	token = (t_cy *)malloc(sizeof(t_cy));
	if (!token)
		return (NULL);
	token->rgb.r = 0;
	token->rgb.g = 0;
	token->rgb.b = 0;
	token->cor.x = 0.0;
	token->cor.y = 0.0;
	token->cor.z = 0.0;
	token->vec.x = 0.0;
	token->vec.y = 0.0;
	token->vec.z = 0.0;
	token->diameter = 0,0;
	token->height = 0.0;
	token->check = false;
	token->prev = NULL;
	token->next = NULL;
	return (token);
}

t_cy	*ft_lstadd_back_cy(t_cy *lst, t_cy *new)
{
	t_cy	*node;

	if (!lst || !new)
		return (NULL);
	node = lst;
	if (lst == NULL)
	{
		lst = new;
		return (lst);
	}
	while (node->next)
		node = node->next;
	node->next = new;
	new->prev = node;
	return (new);
}

double	ft_hit_cylinder(t_cy *cyl, t_vec r_o, t_vec rd)
{
	t_quadra	p;
	t_vec		top;
	t_vec		roco;
	double		h_2;

	top = ft_vec_multi_dot(ft_normalize_vec(ft_vec_multi_dot(cyl->vec, cyl->height)),
			cyl->height);
	h_2 = ft_vecdot(top, top);
	roco = ft_subvec(r_o, cyl->cor);
	p.a = h_2 - ft_vecdot(top, rd) * ft_vecdot(top, rd);
	p.b = h_2 * ft_vecdot(roco, rd) - ft_vecdot(top, roco) * ft_vecdot(top, rd);
	p.c = h_2 * ft_vecdot(roco, roco) - ft_vecdot(top, roco)
		* ft_vecdot(top, roco) - (cyl->diameter) * (cyl->diameter) * h_2;
	if ((p.b * p.b - p.a * p.c) < 0)
		return (-1);
	p.t1 = (-p.b - sqrtf((p.b * p.b - p.a * p.c))) / p.a;
	p.t = ft_vecdot(top, roco) + (p.t1) * ft_vecdot(top, rd);
	if (p.t > 0 && p.t < h_2)
		return (p.t1);
	p.t = ft_calc_root_cy(ft_vecdot(top, roco), ft_vecdot(top, rd), h_2, p.t);
	if (fabs(p.b + p.a * p.t) < sqrtf((p.b * p.b - p.a * p.c)))
		return (p.t);
	return (-1);
}
