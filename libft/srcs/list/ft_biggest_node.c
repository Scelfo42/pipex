#include "../../header/libft.h"

int	ft_biggest(t_node *top)
{
	int		biggest;
	t_node	*tmp;

	biggest = 0;
	tmp = top;
	while (top)
	{
		top = top->next;
		while (top && tmp->data > top->data)
			top = top->next;
		biggest = tmp->data;
		tmp = top;
	}
	return (biggest);
}
