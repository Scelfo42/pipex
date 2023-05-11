/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscelfo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 17:15:20 by cscelfo           #+#    #+#             */
/*   Updated: 2023/05/11 18:43:40 by cscelfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/ft_pipex.h"

char	**ft_getpath_add_slash(char **envp)
{
	char	**path;
	char	**tmp;
	int		i;

	tmp = ft_split(&(envp[34][28]), ':');
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
	char	**test_cmd_no_flag;
	int		i;
	char	*cmd_path;

	test_cmd_no_flag = ft_split(cmd_to_try, ' ');
	if (!test_cmd_no_flag)
		return (false);
	i = -1;
	while (data->env[++i])
	{
		cmd_path = ft_strjoin(data->env[i], test_cmd_no_flag[0]);
		if (access(cmd_path, F_OK | X_OK))
		{
			if (data->cmd[0])
				data->cmd[1] = cmd_to_try;
			else
				data->cmd[0] = cmd_to_try;
			return (true);
		}
		free(cmd_path);
	}
	return (false);
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
	else
	{
		ft_printf("\nCONGRATULATIONS! '%s' and '%s' are both valid commands\n\n", data->cmd[0], data->cmd[1]);
	}
/*
	while (cmd[++i])
	{
		j = 0;
		while (envp[j])
		{
			access_return = access(envp[j], F_OK);
			if (access_return == 0)
			{
				ft_printf("\ncommand '%s' is valid\n\n", cmd[i]);
				break ;
			}
			ft_printf("\naccess: %d\n\n", access_return);
			ft_printf("\nenvp[%d]: '%s'\n\n", j, envp[j]);
			j++;
		}
	}*/
/*	while (envp[++i])
		ft_printf("envp[%d]: [%s]\n", i, envp[i]);*/
	return (0);
}
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
