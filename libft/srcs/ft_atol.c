/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscelfo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 15:44:09 by cscelfo           #+#    #+#             */
/*   Updated: 2023/04/07 15:44:42 by cscelfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fl_header/ft_first_layer.h"

long int	ft_atol(char *str)
{
	long int	result;
	int			sign;
	int			i;

	result = 0;
	sign = 1;
	i = 0;
	while ((str[i] == ' ') || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-')
		sign *= -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = (result * 10) + str[i] - 48;
		i++;
	}
	return (result * sign);
}
/*
int	main(void)
{
	long int	num1 = ft_atol("0");
	long int	num2 = ft_atol("2147483647");
	long int	num3 = ft_atol("2147483649"); //riparte dal min_int! Serve il long
	long int num4 = ft_atol("-2147483648");
	long int num5 = ft_atol("-2147483649");
	long int num6 = ft_atol("-1");
	long int num7 = ft_atol("1");
	
	printf("\n\n0 [%ld]\n\n", num1);
	printf("\n\nmax-int: [%ld]\n\n", num2);
	printf("\n\nmax-int+2: [%ld]\n\n", num3);
	printf("\n\nmin-int: [%ld]\n\n", num4);
	printf("\n\nmin-int-1: [%ld]\n\n", num5);
	printf("\n\n-1: [%ld]\n\n", num6);
	printf("\n\n1: [%ld]\n\n", num7);
}*/
