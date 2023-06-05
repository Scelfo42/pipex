/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmd_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chri42 <chri42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 21:27:01 by cscelfo           #+#    #+#             */
/*   Updated: 2023/05/25 09:42:54 by cscelfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/ft_pipex.h"

void	ft_error_message(void)
{
	ft_putstr_fd("\nNot enough arguments given!\n\n", 2);
	ft_putstr_fd("-------------------------------------------------\n", 2);
	ft_putstr_fd("|\t\t\t\t\t\t|\n", 2);
	ft_putstr_fd("|\tThe correct prompt should be:\t\t|\n", 2);
	ft_putstr_fd("|\t\t\t\t\t\t|\n", 2);
	ft_putstr_fd("|\t\t\t\t\t\t|\n", 2);
	ft_putstr_fd("|./pipex infile 'cmd1' ", 2);
	ft_putstr_fd("'cmd2' 'cmdn...' outfile |\n", 2);
	ft_putstr_fd("|\t\t\t\t\t\t|\n", 2);
	ft_putstr_fd("-------------------------------------------------\n\n", 2);
	exit(EXIT_FAILURE);
}

void	ft_no_file_message(char *file_name)
{
	ft_putstr_fd("cscelfo-bash: ", 2);
	ft_putstr_fd(file_name, 2);
	ft_putstr_fd(": no such file or directory ", 2);
	return ;
}

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
