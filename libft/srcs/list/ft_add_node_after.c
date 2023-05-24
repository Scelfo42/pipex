/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_node_after.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chri42 <chri42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 21:30:06 by chri42            #+#    #+#             */
/*   Updated: 2023/05/24 21:30:07 by chri42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
