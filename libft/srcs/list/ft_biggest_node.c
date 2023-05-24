/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_biggest_node.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chri42 <chri42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 21:29:14 by chri42            #+#    #+#             */
/*   Updated: 2023/05/24 21:29:15 by chri42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
