/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_node_before.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chri42 <chri42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 21:30:10 by chri42            #+#    #+#             */
/*   Updated: 2023/05/24 21:30:10 by chri42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
