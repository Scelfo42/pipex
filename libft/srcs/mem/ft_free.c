/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscelfo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 15:17:48 by cscelfo           #+#    #+#             */
/*   Updated: 2023/05/18 18:17:54 by cscelfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/libft.h"

void	*ft_free(void **ptr)
{
	if (*ptr)
	{
		free(*ptr);
		*ptr = 0;
	}
	return (*ptr);
}

void	ft_free_stack(t_stack **stack)
{
	if ((*stack)->size > 1)
	{
		while ((*stack)->top->next)
		{
			(*stack)->top = (*stack)->top->next;
			free((*stack)->top->prev);
		}
	}
	if ((*stack)->size != 0)
		free((*stack)->top);
	free(*stack);
}

void	ft_free_matrix(char **matrix)
{
	int	i;

	i = -1;
	while (matrix[++i])
		ft_free((void **)&matrix[i]);
	free(matrix);
	matrix = NULL;
}
