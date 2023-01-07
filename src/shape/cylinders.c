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
	token->r = 0;
	token->g = 0;
	token->b = 0;
	token->x = 0.0;
	token->y = 0.0;
	token->z = 0.0;
	token->vx = 0.0;
	token->vy = 0.0;
	token->vz = 0.0;
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