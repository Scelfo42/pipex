/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscelfo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 13:05:45 by cscelfo           #+#    #+#             */
/*   Updated: 2023/04/05 15:42:51 by cscelfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fl_header/ft_first_layer.h"

int	ft_atoi(char *nptr)
{
	int		result;
	int		sign;
	int		i;

	result = 0;
	sign = 1;
	i = 0;
	while ((nptr[i] == ' ') || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '-')
		sign *= -1;
	if (nptr[i] == '-' || nptr[i] == '+')
		i++;
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		result = (result * 10) + nptr[i] - '0';
		i++;
	}
	return (result * sign);
}
/*
int	main(void)
{
	int	num1 = ft_atoi("0");
	int	num2 = ft_atoi("2147483647");
	int	num3 = ft_atoi("2147483649"); //riparte dal min_int! Serve il long
	int num4 = ft_atoi("-2147483648");
	int num5 = ft_atoi("-1");
	
	ft_printf("\n\nnum1: [%d]\n\n", num1);
	ft_printf("\n\nnum2: [%d]\n\n", num2);
	ft_printf("\n\nnum3: [%d]\n\n", num3);
	ft_printf("\n\nnum4: [%d]\n\n", num4);
	ft_printf("\n\nnum5: [%d]\n\n", num5);
}*/
