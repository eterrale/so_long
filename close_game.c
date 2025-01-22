/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeisler <ekeisler@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 10:40:11 by ekeisler          #+#    #+#             */
/*   Updated: 2025/01/22 19:40:17 by ekeisler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	destroy_and_free(t_data *data)
{
	int	i;

	i = 0;
	while (i < NUM_IMG)
	{
		if (data->img[i].addr)
			mlx_destroy_image(data->mlx, data->img[i].addr);
		i++;
	}
	if (data->win)
		mlx_destroy_window(data->mlx, data->win);
	mlx_loop_end(data->mlx);
}

int	close_game(t_data *data)
{
	destroy_and_free(data);
	return (0);
}

int	free_game(t_data *data)
{
	mlx_destroy_display(data->mlx);
	free_map(&data->map);
	free(data->mlx);
	return (0);
}
