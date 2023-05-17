/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscelfo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 17:15:20 by cscelfo           #+#    #+#             */
/*   Updated: 2023/05/12 15:40:21 by cscelfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/ft_pipex.h"

char	**ft_getpath_add_slash(char **envp)
{
	char	**path;
	char	**tmp;
	char	*str;
	int		i;

	str = "PATH=/";
	i = 0;
	while (ft_strncmp(str, envp[i], 6))
		i++;
	tmp = ft_split(&(envp[i][28]), ':');
	path = ft_calloc(ft_matlen(tmp) + 1, sizeof(char *));
	i = -1;
	while (tmp[++i])
	{
		path[i] = ft_strjoin(tmp[i], "/");
		free(tmp[i]);
	}
	free(tmp);
	return (path);
}

bool	ft_test_validity(t_data *data, char *cmd_to_try)
{
	char	**cmd_no_flag;
	int		i;
	char	*cmd_path;

	cmd_no_flag = ft_split(cmd_to_try, ' ');
	if (!cmd_no_flag)
		return (false);
	i = -1;
	while (data->env[++i])
	{
		cmd_path = ft_strjoin(data->env[i], cmd_no_flag[0]);
		if (access(cmd_path, F_OK | X_OK) == 0)
		{
			if (data->cmd[0])
				data->cmd[1] = ft_strdup(cmd_path);
			else
				data->cmd[0] = ft_strdup(cmd_path);
			ft_free_argv(cmd_no_flag);
			ft_free((void *)&cmd_path);
			return (true);
		}
		ft_free((void *)&cmd_path);
	}
	ft_free_argv(cmd_no_flag);
	return (false);
}

void	ft_exec_cmd(t_data *data, char **argv)
{
	int	pipe_fd[2]; // pipe_fd[0] = read | pipe_fd[1] = write //

	if (pipe(pipe_fd) == -1)
	{
		perror("pipe: ");
		exit(1);
	}

	data->pid = fork();
	if (data->pid < 0)
	{
		perror("pid: ");
		exit(2);
	}
	if (data->pid == 0)
	{
		close(pipe_fd[0]); //nothing to be read
		int file1 = open(data->file1, O_RDONLY);
		if (file1 == -1)
		{
			ft_printf("%s not found\n", data->file1);
			exit(1);
		}
		dup2(file1, STDIN_FILENO);
		dup2(pipe_fd[1], STDOUT_FILENO); //scrivo nello standard output dal pipe[1] cosi' da poter leggerlo dal pipe[0] nel parent dallo standard input
		close(pipe_fd[1]);
		execve(data->cmd[0], ft_split(argv[2], ' '), data->env);
		exit(0);
	}
	close(pipe_fd[1]); //nothing to be written
	int file2 = open(data->file2, O_CREAT | O_TRUNC | O_WRONLY, 0644);
	if (file2 == -1)
	{
		ft_printf("An error occured in the creation of %s\n", data->file2);
		exit(1);
	}
	waitpid(data->pid, NULL, 0);
	dup2(file2, STDOUT_FILENO);
	dup2(pipe_fd[0], STDIN_FILENO);
	close(pipe_fd[1]);
	execve(data->cmd[1], ft_split(argv[3], ' '), data->env);
	close(pipe_fd[0]);
	return;
}

int	main(int argc, char **argv, char **envp)
{
	t_data	*data;

	if (argc < 5 || argc > 5)
	{
		ft_printf("Not enough argument or too many arguments\n");
		return (1);
	}
	data = ft_calloc(1, sizeof(t_data));
	data->env = ft_getpath_add_slash(envp);
	if (!data->env)
		return (2);
	data->cmd = ft_calloc(2, sizeof(char *));
	if ((!ft_test_validity(data, argv[2])) 
		|| (!ft_test_validity(data, argv[3])))
	{
		ft_free_world(data);
		ft_printf("BOBBEI command not found\n");
		return (3);
	}
	data->file1 = argv[1];
	data->file2 = argv[4];
	ft_exec_cmd(data, argv);
	ft_free_world(data);
	return (0);
}
