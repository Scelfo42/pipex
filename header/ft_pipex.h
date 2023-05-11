/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscelfo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 17:15:52 by cscelfo           #+#    #+#             */
/*   Updated: 2023/05/11 18:48:40 by cscelfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PIPEX_H
# define FT_PIPEX_H

# include "../libft/header/libft.h"
# include <stdio.h>
# include <errno.h>
# include <fcntl.h>


typedef struct s_data
{
	char	**cmd;
	char	**env;
}	t_data;

#endif
