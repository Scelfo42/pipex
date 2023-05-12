/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscelfo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 14:44:52 by cscelfo           #+#    #+#             */
/*   Updated: 2023/05/01 15:20:30 by cscelfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/libft.h"

char	*ft_strdup(char *s)
{
	char	*new_s;
	size_t	s_len;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s) + 1;
	new_s = ft_calloc(s_len, sizeof(char));
	if (!new_s)
		return (NULL);
	ft_memcpy(new_s, s, s_len);
	if (!*new_s)
		ft_free((void **)&new_s);
	return (new_s);
}
/*
#include <stdio.h>
int	main()
{
	char	*s = NULL;
	printf("%s\n", ft_strdup(s));
	free(s);
}*/
