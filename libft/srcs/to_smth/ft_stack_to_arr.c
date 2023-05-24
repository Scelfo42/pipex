/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_to_arr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chri42 <chri42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 21:30:50 by chri42            #+#    #+#             */
/*   Updated: 2023/05/24 21:30:51 by chri42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
