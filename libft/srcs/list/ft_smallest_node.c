#include "../../header/libft.h"

int	ft_smallest(t_node *top)
{
	int		smallest;
	t_node	*tmp;

	smallest = 0;
	tmp = top;
	while (top)
	{
		top = top->next;
		while (top && tmp->data < top->data)
			top = top->next;
		smallest = tmp->data;
		tmp = top;
	}
	return (smallest);
}
