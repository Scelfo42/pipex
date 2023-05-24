/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_smallest_node.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chri42 <chri42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 21:28:40 by chri42            #+#    #+#             */
/*   Updated: 2023/05/24 21:28:41 by chri42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
