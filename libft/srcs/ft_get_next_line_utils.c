/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscelfo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 18:24:53 by cscelfo           #+#    #+#             */
/*   Updated: 2023/03/15 16:53:18 by cscelfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fl_header/ft_first_layer.h"

int	found_new_line(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*ft_cpy(char *dest, char *tmp, char *source, size_t start)
{
	size_t	j;
	size_t	i;

	j = 0;
	i = start;
	if (tmp)
	{
		while (i > 0)
		{
			dest[j] = tmp[j];
			j++;
			i--;
		}
	}
	j = 0;
	while (source[j] != '\0')
	{
		dest[start + j] = source[j];
		j++;
	}
	return (dest);
}
