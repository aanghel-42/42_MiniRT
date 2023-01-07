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
	token->r = 0;
	token->g = 0;
	token->b = 0;
	token->x = 0.0;
	token->y = 0.0;
	token->z = 0.0;
	token->vx = 0.0;
	token->vy = 0.0;
	token->vz = 0.0;
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

