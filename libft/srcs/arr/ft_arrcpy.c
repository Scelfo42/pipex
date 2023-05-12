/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscelfo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 15:58:16 by cscelfo           #+#    #+#             */
/*   Updated: 2023/05/12 15:58:37 by cscelfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/libft.h"

int	*ft_arrcpy(int *arr, int size)
{
	int	*new_arr;
	int	i;

	new_arr = ft_calloc(size, sizeof(int));
	i = -1;
	while (++i < size)
		new_arr[i] = arr[i];
	return (new_arr);
}
