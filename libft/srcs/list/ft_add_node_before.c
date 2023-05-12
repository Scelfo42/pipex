#include "../../header/libft.h"

void	ft_add_before(t_node *first_node, t_stack **to)
{
	if (first_node)
	{
		if ((*to)->top)
		{
			(*to)->top->prev = first_node;
			first_node->next = (*to)->top;
			(*to)->top = (*to)->top->prev;
		}
		else
		{
			(*to)->top = first_node;
			(*to)->bottom = (*to)->top;
		}
	}
}
