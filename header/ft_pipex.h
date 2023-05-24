/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chri42 <chri42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 17:15:52 by cscelfo           #+#    #+#             */
/*   Updated: 2023/05/24 21:31:09 by chri42           ###   ########.fr       */
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
# include <sys/stat.h>
# include <signal.h>

typedef struct s_data
{
	char	**cmd1;
	char	**cmd2;
	char	**envp;
	char	*file1;
	char	*file2;
}	t_data;

char	*ft_cmd_path(char *cmd, char **env);
char	**ft_get_cmd(char *cmd, char **envp);
char	**ft_get_env(char *line, char **envp);

#endif
