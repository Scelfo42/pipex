/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscelfo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 16:06:30 by cscelfo           #+#    #+#             */
/*   Updated: 2023/04/11 16:14:30 by cscelfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/libft.h"

char	*ft_strtrim(char *s1, char *set)
{
	size_t	start;
	size_t	end;

	start = 0;
	if (!s1 || !set)
		return (ft_strdup(s1));
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	end = ft_strlen(s1);
	if (start != end)
	{
		while (ft_strchr(set, s1[end]))
			end--;
		free(set);
		return (ft_substr(s1, start, (end - start + 1)));
	}
	free(set);
	return (ft_strdup(&s1[start]));
}
