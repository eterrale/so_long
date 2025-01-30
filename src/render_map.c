/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeisler <ekeisler@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 20:20:06 by ekeisler          #+#    #+#             */
/*   Updated: 2025/01/30 16:45:40 by ekeisler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	handle_tile(t_data *data, int x, int y, char tile);

// 
// This function render our map visually.
// 
int	render_map(t_data *data)
{
	int	x;
	int	y;
	int	i;
	int	j;

	y = 0;
	i = 0;
	data->count_move = 0;
	while (data->map.grid[i])
	{
		x = 0;
		j = 0;
		while (data->map.grid[i][j] != '\0')
		{
			put_tile_to_window(data, x, y, 2);
			handle_tile(data, x, y, data->map.grid[i][j]);
			x += 64;
			j++;
		}
		y += 64;
		i++;
	}
	return (0);
}

// 
// This function put on image on our
// window in a given x y position..
// 
void	put_tile_to_window(t_data *data, int x, int y, int tile)
{
	mlx_put_image_to_window(data->mlx, data->win, data->img[tile].addr, x, y);
}

// 
// This function handle each case image according
// to his 'ID' on the map grid.
// 
static void	handle_tile(t_data *data, int x, int y, char tile)
{
	if (tile == '1')
		put_tile_to_window(data, x, y, 1);
	else if (tile == 'P')
	{
		data->player.pos_x = x;
		data->player.pos_y = y;
		data->player.grid_x = x / 64;
		data->player.grid_y = y / 64;
		put_tile_to_window(data, x, y, 3);
	}
	else if (tile == 'C')
		put_tile_to_window(data, x, y, 4);
	else if (tile == 'E')
	{
		put_tile_to_window(data, x, y, 9);
		data->map.exit_x = x;
		data->map.exit_y = y;
	}
}
