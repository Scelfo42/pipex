/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscelfo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 12:39:18 by cscelfo           #+#    #+#             */
/*   Updated: 2023/03/24 16:01:49 by cscelfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/libft.h"

double	ft_atof(char *str)
{
	int		i;
	double	res;
	int		sign;
	double	dec;

	i = 0;
	sign = 1;
	res = 0.0;
	dec = 1.0;
	if (str[i] == '-')
		sign = -1;
	i += (str[i] == '-' || str[i] == '+');
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - '0');
		i++;
	}
	if (str[i] == '.')
		i++;
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i++] - '0');
		dec *= 10;
	}
	return (res / dec * sign);
}
