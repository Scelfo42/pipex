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
				data->cmd[1] = cmd_path;
			else
				data->cmd[0] = cmd_path;
			ft_free_argv(cmd_no_flag);
			ft_free((void *)&cmd_path);
			return (true);
		}
		ft_free((void *)&cmd_path);
	}
	return (false);
}

void	ft_exec_cmd(t_data *data)
{
	int	pipe_fd[2];

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
		dup2(pipe_fd[1], STDOUT_FILENO);
		close(pipe_fd[0]);
		close(pipe_fd[1]);
		//execve(data->cmd[0], ft_split(data->cmd[0], ' '), data->env);
	}
	//waitpid(data->pid, NULL, 0);
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
		ft_printf("An error of command validity has occured\n");
		return (3);
	}
	ft_exec_cmd(data);
	ft_free_world(data);
	return (0);
}
/*	else
	{
		ft_printf("\nCONGRATULATIONS! '%s' and '%s' are both valid commands\n\n", data->cmd[0], data->cmd[1]);
	}*/
/*
{
	int	fd[2];
	int	childpid;
	char **av;
	
	av = ft_calloc(10, sizeof(char *));
	pipe(fd);
	childpid = fork();
	if (childpid == 0)
	{
		av[0] = "/bin/echo";
		av[1] = ft_strjoin(argv[1], argv[2]);
		av[2] = NULL;
		close(fd[0]); //closed unused read end
		dup2(fd[1], 1); //closed stdout and redirecting it into write end
		close(fd[1]); //closed original write end cause it's duplicated now
		if (execve(av[0], av, NULL) == -1)
			perror("execve e' na mmerda");
		exit(0);
	}
	//parent process takes echo's output and pass it to tr's input
	av[0] = "/usr/bin/tr";
	av[1] = "-d";
	av[2] = "_";
	av[3] = NULL;
	close(fd[1]); //closed unused write end
	dup2(fd[0], 0); //closed stdin and redirecting it into read end
	close(fd[0]); //closed original read end cause it's duplicated now
	if (execve(av[0], av, NULL) == -1)
		perror("execve e' na mmerda");
	(void)argc;
	return (0);
}*/
