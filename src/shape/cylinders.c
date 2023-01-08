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