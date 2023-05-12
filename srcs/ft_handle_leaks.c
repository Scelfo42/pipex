#include "../header/ft_pipex.h"

void	ft_free_world(t_data *data)
{
	int	i;

	i = -1;
	while (data->env[++i])
		free(data->env[i]);
	free(data->env);
	free(data->cmd);
	free(data);
}
