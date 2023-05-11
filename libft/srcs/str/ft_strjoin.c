/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscelfo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 15:16:29 by cscelfo           #+#    #+#             */
/*   Updated: 2023/05/11 17:35:23 by cscelfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/libft.h"

char	*ft_strjoin(char *s1, char *s2)
{
	int		c;
	int		k;
	char	*new;

	c = 0;
	k = 0;
	new = ft_calloc(ft_strlen(s1) + ft_strlen(s2) + 1, sizeof(char));
	while (s1[c] != '\0')
	{
		new[c] = s1[c];
		c++;
	}
	while (s2[k] != '\0')
	{
		new[c + k] = s2[k];
		k++;
	}
	new[c + k] = '\0';
	return (new);
}
