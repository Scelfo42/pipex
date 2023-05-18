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

bool	ft_test_validity(t_data *data, char *cmd)
{
	int		i;
	char	*cmd_path;
	char	*join_slash;

	if (!cmd || !cmd[0])
		return (false);
	i = -1;
	while (data->env[++i])
	{
		join_slash = ft_strjoin(data->env[i], "/");
		cmd_path = ft_strjoin(join_slash, cmd);
		if (access(cmd_path, F_OK | X_OK) == 0)
		{
			if (!data->cmd[0])
				data->cmd[0] = ft_strdup(cmd_path);
			else
				data->cmd[1] = ft_strdup(cmd_path);
			ft_free((void **)&join_slash);
			ft_free((void **)&cmd_path);
			return (true);
		}
		ft_free((void **)&join_slash);
		ft_free((void *)&cmd_path);
	}
	return (false);
}

void	ft_check_errors(t_data *data, char **argv)
{
	if (!data->env)
	{
		ft_free_world(data);
		ft_putstr_fd("Environment path not found correctly\n", 2);
		exit(-1);
	}
	data->cmd_no_flag_one = ft_split(argv[2], ' ');
	data->cmd_no_flag_two = ft_split(argv[3], ' ');
	if (!ft_test_validity(data, data->cmd_no_flag_one[0])
		|| !ft_test_validity(data, data->cmd_no_flag_two[0]))
	{
		ft_free_world(data);
		ft_putstr_fd("Command not found\n", 2);
		exit(-1);
	}
	else if (access(argv[1], F_OK) == -1)
		ft_putstr_fd("No such file or directory\n", 2);
	data->file1 = argv[1];
	data->file2 = argv[4];
}
