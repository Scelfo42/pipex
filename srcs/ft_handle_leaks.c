/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_leaks.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscelfo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 17:56:21 by cscelfo           #+#    #+#             */
/*   Updated: 2023/05/18 18:07:55 by cscelfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/ft_pipex.h"

void	ft_free_world(t_data *data)
{
	if (data->cmd)
		ft_free_matrix(data->cmd);
	if (data->cmd_no_flag_one)
		ft_free_matrix(data->cmd_no_flag_one);
	if (data->cmd_no_flag_two)
		ft_free_matrix(data->cmd_no_flag_two);
	free(data);
}
