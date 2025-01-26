/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeisler <ekeisler@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 10:40:11 by ekeisler          #+#    #+#             */
/*   Updated: 2025/01/26 16:04:03 by ekeisler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	destroy_and_free(t_data *data)
{
	int	i;

	i = 0;
	while (i < NUM_IMG)
	{
		if (data->img[i].addr != NULL)
		{
			mlx_destroy_image(data->mlx, data->img[i].addr);
			data->img[i].addr = NULL;
		}
		i++;
	}
	if (data->win != NULL)
	{
		mlx_destroy_window(data->mlx, data->win);
		data->win = NULL;
	}
	if (data->mlx != NULL)
		mlx_loop_end(data->mlx);
}

int	close_game(t_data *data)
{
	destroy_and_free(data);
	ft_putstr_fd("closing game...\n", 1);
	return (0);
}

int	free_game(t_data *data)
{
	if (data->mlx)
		mlx_destroy_display(data->mlx);
	free_map(&data->map);
	if (data->mlx)
		free(data->mlx);
	return (0);
}
