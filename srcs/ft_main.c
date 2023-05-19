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

int	ft_exec_cmd(t_data *data, char **cmd)
{
	int	pid;
	int status;
	int	exit_status;

	pid = fork();
	if (pid < 0)
	{
		perror("fork error: ");
		exit(1);
	}
	if (pid == 0)
		ft_child_process(data, pipe_fd, cmd);
	close(pipe_fd[1]); //nothing to be written
	wait(&status);
	exit_status = WEXITSTATUS(status);
	ft_parent_process(data, pipe_fd);
	return (exit_status);
}

int	ft_caller(int recursion, char **envp, char **argv, int fd_stdout)
{
	char	**cmd;
	int		pipe_fd[2]; // pipe_fd[0] = read | pipe_fd[1] = write

	if (pipe(pipe_fd) == -1)
	{
		perror("pipe: ");
		exit(1);
	}
	if (recursion != 2)
		ft_caller(recursion - 1, envp, argv, pipe_fd[1]);
	else
	{
		close(pipe_fd[0]); //non c'e' nulla da leggere ma solo da scrivere in pipe_fd[1]
		pipe_fd[1] = open(argv[1], O_RDONLY);
	}
	cmd = ft_take_cmd(argv[recursion], envp);
	return (ft_exec_cmd(cmd));
}

int	main(int argc, char **argv, char **envp)
{
	t_data	*data;
	int		process;
	int		recursion;
	int		fd_stdout;

	if (argc < 5)
	{
		perror("Not enough argument or too many arguments: ");
		return (1);
	}
	data = ft_calloc(1, sizeof(t_data));
	recursion = ft_set_variables(data, argv, argc);
	fd_stdout = open(data->file2, O_CREAT | O_TRUNC | O_WRONLY);
	process = ft_caller(recursion, data->envp, argv, fd_stdout);
	ft_free_world(data);
	return (process);
}
