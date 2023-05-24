/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmd_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chri42 <chri42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 21:27:01 by cscelfo           #+#    #+#             */
/*   Updated: 2023/05/24 22:23:05 by chri42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/ft_pipex.h"

char	**ft_get_env(char *line, char **envp)
{
	char	**get_path;
	int		i;
	size_t	path_len;

	i = -1;
	path_len = ft_strlen(line);
	while (envp[++i])
	{
		if (!ft_strncmp(line, envp[i], path_len))
			break ;
		continue ;
	}
	get_path = ft_split(&(envp[i][path_len + 1]), ':');
	return (get_path);
}

char	*ft_cmd_path(char *cmd, char **env)
{
	int		i;
	char	*slash;
	char	*path;

	i = -1;
    slash = NULL;
	while (env && env[++i])
	{
		slash = ft_strjoin(env[i], "/");
		path = ft_strjoin(slash, cmd);
		if (access(path, X_OK) == 0)
			break ;
		ft_free((void **)&slash);
		ft_free((void **)&path);
	}
	ft_free((void **)&slash);
	if (env[i])
		return (path);
	return (NULL);
}

char	**ft_get_cmd(char *cmd, char **envp)
{
	char		**env;
	char		*path;
	char		**cmd_mat;

	env = ft_get_env("PATH=", envp);
	cmd_mat = ft_split(cmd, ' ');
	path = ft_cmd_path(cmd_mat[0], env);
	if (path)
	{
		ft_free((void **)&cmd_mat[0]);
		cmd_mat[0] = ft_strdup(path);
	}
	ft_free_matrix(env);
	ft_free((void **)&path);
	return (cmd_mat);
}
