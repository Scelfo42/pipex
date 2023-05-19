/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_errors.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscelfo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 17:04:17 by cscelfo           #+#    #+#             */
/*   Updated: 2023/05/18 18:22:32 by cscelfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/ft_pipex.h"

char	**ft_getpath(char **envp, char *correct_line)
{
	char	**path;
	int		i;
	int		path_len;

	i = -1;
	path_len = ft_strlen(correct_line);
	while (envp[++i])
	{
		if (!ft_strncmp(envp[i], correct_line, path_len))
			break ;
		continue;
	}
	path = ft_split(&(envp[i][path_len + 1]), ':');
	return (path);
}

char	*ft_join_cmd(char **envp, char *cmd)
{
	int		i;
	char	*executable;
	char	*add_slash;

	i = -1;
	while (envp[i])
	{
		add_slash = ft_strjoin(envp[i], "/");
		executable = ft_strjoin(add_slash, cmd);
		if (access(executable, X_OK) == -1)
			break ;
		ft_free(&add_slash);
		ft_free(&executable);
	}
	ft_free(&add_slash);
	return (executable);
}

char	**ft_take_cmd(t_data *data, char *cmd_wFlag)
{
	char	**cmd_mat;
	char	**env;
	char	*cmd;

	cmd_mat = ft_split(cmd_wFlag, ' ');	
	cmd = ft_join_cmd(data->envp, cmd_mat[0]);
	if (cmd)
	{
		ft_free(&cmd_mat[0]);
		cmd_mat[0] = cmd;
	}
	return (cmd_mat);
}

int	ft_set_variables(t_data *data, char **argv, int argc, char **envp)
{
	int	recursion;

	recursion = 3;
	while (argc-- > 5)
		recursion++;
	data->file1 = argv[1];
	data->file2 = argv[4];
	data->envp = ft_getpath(envp, "PATH=");
	return (recursion);	
}
