/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscelfo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 15:17:48 by cscelfo           #+#    #+#             */
/*   Updated: 2023/05/01 15:21:01 by cscelfo          ###   ########.fr       */
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

void	**ft_free_mat(char ***ptr_mat)
{
	if (*ptr_mat)
	{
		if (**ptr_mat)
			ft_free((void **)*ptr_mat);
		*ptr_mat = 0;
	}
	return ((void **)*ptr_mat);
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

void	ft_free_argv(char **argv)
{
	int	i;

	i = 0;
	while (argv[i])
		free(argv[i++]);
	free(argv);
}
