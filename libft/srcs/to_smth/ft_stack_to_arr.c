#include "../../header/libft.h"

int	*ft_stack_to_arr(t_node *stack_top, int stack_size)
{
	int	*arr;
	int	i;

	arr = (int *)ft_calloc(stack_size, sizeof(int));
	i = 0;
	while (stack_top)
	{
		arr[i++] = stack_top->data;
		stack_top = stack_top->next;
	}
	return (arr);
}
