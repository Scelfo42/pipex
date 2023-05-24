/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chri42 <chri42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 17:15:20 by cscelfo           #+#    #+#             */
/*   Updated: 2023/05/24 22:20:20 by chri42           ###   ########.fr       */
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

void	ft_dup_close(int fd_in, int fd_out, char **cmd, bool flag)
{
	if (fd_in != -1 && flag)
		dup2(fd_in, STDIN_FILENO);
	if (fd_out != -1 && flag)
		dup2(fd_out, STDOUT_FILENO);
	close(fd_in);
	close(fd_out);
	if (!flag)
		ft_free_matrix(cmd);
}

int	ft_child(char **cmd, int fd_in, int fd_out, char **envp)
{
	int	pid;
	int	status;
	int	exittino;

	pid = fork();
	if (pid == 0)
	{
		ft_dup_close(fd_in, fd_out, cmd, true);
		if (execve(cmd[0], cmd, envp) == -1)
		{
			perror("execve: ");
			ft_putstr_fd("Command not found\n", 2);
			ft_dup_close(fd_in, fd_out, cmd, false);
			exit(EXIT_FAILURE);
		}
	}
	ft_dup_close(fd_in, fd_out, cmd, false);
	waitpid(pid, &status, 0);
	exittino = WEXITSTATUS(status);
	return (exittino);
}

int	ft_exec(int ac, char **av, char **envp, int fd_out)
{
	int		pipe_fd[2];
	char	**cmd;

	if (pipe(pipe_fd) == -1)
	{
		perror("pipe: ");
		exit(EXIT_FAILURE);
	}
	if (ac > 2)
		ft_exec((ac - 1), av, envp, pipe_fd[1]);
	else
	{
		pipe_fd[1] = -1;
		pipe_fd[0] = open(av[ac - 1], O_RDONLY);
		if (pipe_fd[0] == -1)
		{
			ft_putstr_fd("infile: no such file or directory\n", 2);
			return (1);
		}
	}
	if (pipe_fd[1] != -1)
		close(pipe_fd[1]);
	cmd = ft_get_cmd(av[ac], envp);
	return (ft_child(cmd, pipe_fd[0], fd_out, envp));
}

int	main(int ac, char **av, char **envp)
{
	int	fd_file2;
	int	child_status;

	if (ac < 5)
		ft_error_message();
	fd_file2 = open(av[--ac], O_CREAT | O_TRUNC | O_WRONLY, 0644);
	if (fd_file2 == -1)
		return (EXIT_FAILURE);
	child_status = ft_exec(--ac, av, envp, fd_file2);
	close(fd_file2);
	return (child_status);
}
