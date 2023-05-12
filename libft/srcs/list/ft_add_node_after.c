#include "../../header/libft.h"

void	ft_add_after(t_stack **a, t_node *new_node)
{
	if (new_node)
	{
		if ((*a)->top)
		{
			(*a)->bottom->next = new_node;
			new_node->prev = (*a)->bottom;
			(*a)->bottom = new_node;
		}
		else
		{
			(*a)->top = new_node;
			(*a)->bottom = (*a)->top;
		}
	}
}
