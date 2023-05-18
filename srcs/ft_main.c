/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscelfo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 17:15:20 by cscelfo           #+#    #+#             */
/*   Updated: 2023/05/18 18:06:56 by cscelfo          ###   ########.fr       */
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

void	ft_exec_cmd(t_data *data)
{
	int	pipe_fd[2]; // pipe_fd[0] = read | pipe_fd[1] = write
	int	pid;

	if (pipe(pipe_fd) == -1)
	{
		perror("pipe error");
		exit(-1);
	}

	pid = fork();
	if (pid < 0)
	{
		perror("fork error");
		exit(-1);
	}
	if (pid == 0)
	{
		//ft_child_process();
		close(pipe_fd[0]); //nothing to be read
		int file1 = open(data->file1, O_RDONLY);
		if (file1 == -1)
			exit(-1);
		dup2(file1, STDIN_FILENO);
		dup2(pipe_fd[1], STDOUT_FILENO);
		close(pipe_fd[1]);
		execve(data->cmd[0], data->cmd_no_flag_one, data->env);
		exit(0);
	}
	close(pipe_fd[1]); //nothing to be written
	waitpid(pid, NULL, 0);
	//ft_parent_process();
	int file2 = open(data->file2, O_CREAT | O_TRUNC | O_WRONLY, 0644);
	if (file2 == -1)
		exit(-1);
	dup2(file2, STDOUT_FILENO);
	dup2(pipe_fd[0], STDIN_FILENO);
	execve(data->cmd[1], data->cmd_no_flag_two, data->env);
	close(pipe_fd[0]);
}

int	main(int argc, char **argv, char **envp)
{
	t_data	*data;

	if (argc < 5 || argc > 5)
	{
		ft_putstr_fd("Not enough argument or too many arguments\n", 2);
		return (0);
	}
	data = ft_calloc(1, sizeof(t_data));
	data->env = ft_getpath(envp, "PATH=");
	data->cmd = ft_calloc(2, sizeof(char *));
	ft_check_errors(data, argv);
	ft_exec_cmd(data);
	ft_free_world(data);
	return (0);
}
