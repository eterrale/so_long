/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeisler <ekeisler@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 20:20:06 by ekeisler          #+#    #+#             */
/*   Updated: 2025/01/26 15:05:39 by ekeisler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	render_map(t_data *data)
{
	int	x;
	int	y;
	int	i;
	int	j;

	check_rules_map(data);
	y = 0;
	i = 0;
	data->map.number_c = 0;
	data->count_move = 0;
	while (data->map.grid[i])
	{
		x = 0;
		j = 0;
		while (data->map.grid[i][j] != '\0')
		{
			mlx_put_image_to_window(data->mlx, data->win,
				data->img[2].addr, x, y);
			if (data->map.grid[i][j] == '1')
				mlx_put_image_to_window(data->mlx, data->win,
					data->img[1].addr, x, y);
			if (data->map.grid[i][j] == 'P')
			{
				data->player.posX = x;
				data->player.posY = y;
				data->player.gridX = j;
				data->player.gridY = i;
				mlx_put_image_to_window(data->mlx, data->win,
					data->img[3].addr, x, y);
			}
			if (data->map.grid[i][j] == 'C')
			{
				mlx_put_image_to_window(data->mlx, data->win,
					data->img[4].addr, x, y);
				data->map.number_c += 1;
			}
			if (data->map.grid[i][j] == 'E')
				mlx_put_image_to_window(data->mlx, data->win,
					data->img[8].addr, x, y);
			x += 64;
			j++;
		}
		y += 64;
		i++;
	}
	return (0);
}
