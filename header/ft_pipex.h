/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscelfo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 17:15:52 by cscelfo           #+#    #+#             */
/*   Updated: 2023/05/12 15:40:10 by cscelfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PIPEX_H
# define FT_PIPEX_H

# include "../libft/header/libft.h"
# include <stdio.h>
# include <errno.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/wait.h>


typedef struct s_data
{
	char	**cmd;
	char	**env;
//	int		pipe_fd[2];
	int		pid;
	char	*file1;
	char	*file2;
}	t_data;

void	ft_free_world(t_data *data);

#endif
