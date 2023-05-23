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
		continue;
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
	while (env[++i])
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
	char	**env;
	char	*path;
	char	**cmd_mat;

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

int	ft_children(char **cmd, int fd_in, int fd_out, char **envp)
{
	int	pid;
	int	status;
	int	exittino;

	pid = fork();
	if (pid == 0)
	{
		dup2(fd_in, STDIN_FILENO);
		dup2(fd_out, STDOUT_FILENO);
		execve(cmd[0], cmd, envp);
		perror("Command: ");
		close(fd_in);
		close(fd_out);
		exit(127);
	}
	close(fd_in);
	close(fd_out);
	waitpid(pid, &status, 0);
	exittino = WEXITSTATUS(status);
	return (exittino);
}

int	ft_exec(int ac, char **av, char **envp, int fd_file2)
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
		pipe_fd[0] = open(av[ac - 1], O_RDONLY);
		if (pipe_fd[0] == -1)
			exit(EXIT_FAILURE);
		pipe_fd[1] = -1;
	}
	cmd = ft_get_cmd(av[ac], envp);
	return (ft_children(cmd, pipe_fd[0], fd_file2, envp));
}

int	main(int ac, char **av, char **envp)
{
	int	fd_file2;
	int	child_status;

	if (ac < 5)
	{
		ft_putstr_fd("Not enough argument or too many arguments\n", 2);
		return (EXIT_FAILURE);
	}
	fd_file2 = open(av[--ac], O_CREAT | O_TRUNC | O_WRONLY, 0644); //file2 has to be opened no matter what
	if (fd_file2 == 1)
		return (EXIT_FAILURE);
	child_status = ft_exec(--ac, av, envp, fd_file2);
	return (child_status); //here the exit status of the child process will be returned
}
