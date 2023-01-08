#include "../../inc/minirt.h"

t_sp	*ft_rtr_head_sp(t_sp *sp)
{
	while (sp)
	{
		if (!sp->prev)
			break ;
		sp = sp->prev;
	}
	return (sp);
}

t_sp	*ft_lstnew_sp(t_sp *sp)
{
	t_sp	*token;

	token = (t_sp *)malloc(sizeof(t_sp));
	if (!token)
		return (NULL);
	token->rgb.r = 0;
	token->rgb.g = 0;
	token->rgb.b = 0;
	token->cor.x = 0.0;
	token->cor.y = 0.0;
	token->cor.z = 0.0;
	token->diameter = 0.0;
	token->check = false;
	token->prev = NULL;
	token->next = NULL;
	return (token);
}

t_sp	*ft_lstadd_back_sp(t_sp *lst, t_sp *new)
{
	t_sp	*node;

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

t_sp	*ft_init_sp(t_sp	*sp)
{
	if (sp->check)
		sp = ft_lstadd_back_sp(sp, ft_lstnew_sp(sp));
	return (sp);
}
