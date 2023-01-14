#include "../../inc/minirt.h"

t_pl	*ft_rtr_head_pl(t_pl *pl)
{
	while (pl)
	{
		if (!pl->prev)
			break ;
		pl = pl->prev;
	}
	return (pl);
}

t_pl	*ft_lstnew_pl(t_pl *pl)
{
	t_pl	*token;

	token = (t_pl *)malloc(sizeof(t_pl));
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
	token->check = false;
	token->prev = NULL;
	token->next = NULL;
	return (token);
}

t_pl	*ft_lstadd_back_pl(t_pl *lst, t_pl *new)
{
	t_pl	*node;

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

double	ft_hit_plane(t_pl *pl, t_vec r_o, t_vec rd)
{
	double	a;
	double	b;
	double	t;

	a = ft_vecdot(ft_subvec(pl->cor, r_o), ft_normalize_vec(pl->vec));
	b = ft_vecdot(rd, ft_normalize_vec(pl->vec));
	t = a / b;
	return (t);
}
