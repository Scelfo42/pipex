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

#include "../fl_header/ft_first_layer.h"

void	*ft_free_void(void **ptr)
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
		{
			ft_free_void((void **)*ptr_mat);
		}
		*ptr_mat = 0;
	}
	return ((void **)*ptr_mat);
}
