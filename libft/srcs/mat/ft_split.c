/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscelfo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 17:30:19 by cscelfo           #+#    #+#             */
/*   Updated: 2023/05/11 15:49:13 by cscelfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/libft.h"

static char	*ft_char_to_str(char c)
{
	char	*str;

	str = (char *)malloc(sizeof(char) * 2);
	if (!str)
		return (0);
	str[0] = c;
	str[1] = '\0';
	return (str);
}

int	ft_countstr(char *s, char c)
{
	int	num_str;
	int	i;

	num_str = 0;
	i = 0;
	if (!s)
		return (num_str);
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		num_str += 1;
		while (s[i] && s[i] != c)
			i++;
	}
	return (num_str);
}

char	**ft_split(char *s, char c)
{
	t_var		var;

	var.i = 0;
	var.k = 0;
	var.j = 0;
	var.trim = ft_strtrim(s, ft_char_to_str(c));
	if (!var.trim || !*var.trim)
		return (NULL);
	var.nb_str = ft_countstr(var.trim, c);
	var.arr_p = ft_calloc(var.nb_str + 1, sizeof(char *));
	if (!var.arr_p)
		return (NULL);
	while (var.i < var.nb_str)
	{
		if (var.trim[++var.j] == c || var.trim[var.j] == '\0')
		{
			var.arr_p[var.i++] = ft_substr(var.trim, var.k, var.j - var.k);
			while (var.trim[var.j] == c)
				var.j++;
			var.k = var.j;
		}
	}
	var.arr_p[var.i] = 0;
	free(var.trim);
	return (var.arr_p);
}
/*
#include <stdio.h>
int	main()
{
	int	nbstr = ft_countstr(0, 0);
	char	**arr_of_pointers = ft_split(0, 0);
	for (int i = 0; i < nbstr; i++)
	{
		printf("%s\n", arr_of_pointers[i]);
		free(arr_of_pointers[i]);
	}
	free(arr_of_pointers);
}*/
