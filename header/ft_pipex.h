/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscelfo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 17:15:52 by cscelfo           #+#    #+#             */
/*   Updated: 2023/05/18 18:14:27 by cscelfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PIPEX_H
# define FT_PIPEX_H

# include "../libft/header/libft.h"
# include <stdio.h>
# include <errno.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/wait.h>


typedef struct s_data
{
	char	**cmd;
	char	**env;
	char	**cmd_no_flag_one;
	char	**cmd_no_flag_two;
	char	*file1;
	char	*file2;
}	t_data;

/*	TEST_CMD	*/
bool	ft_test_validity(t_data *data, char *cmd);
/*	HANDLE ERRORS	*/
void	ft_check_errors(t_data *data, char **argv);
/*	HANDLE LEAKS	*/
void	ft_free_world(t_data *data);

#endif
