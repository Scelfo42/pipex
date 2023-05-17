#include "../header/ft_pipex.h"

void	ft_free_world(t_data *data)
{
	int	i;

	i = -1;
	while (data->env[++i])
		free(data->env[i]);
	free(data->env);
	i = -1;
	while (data->cmd[++i])
		free(data->cmd[i]);
	free(data->cmd);
	free(data);
}
