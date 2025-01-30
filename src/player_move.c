/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeisler <ekeisler@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 16:00:01 by ekeisler          #+#    #+#             */
/*   Updated: 2025/01/30 18:30:34 by ekeisler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

// 
// This function move the player forward.
// 
int	p_moveforward(t_data *data, t_player *player, t_map *map)
{
	put_tile_to_window(data, player->pos_x, player->pos_y, 5);
	if (map->grid[player->grid_y - 1][player->grid_x] != '1')
	{
		put_tile_to_window(data, player->pos_x, player->pos_y, 2);
		player->pos_y -= 64;
		put_tile_to_window(data, player->pos_x, player->pos_y, 5);
		if (map->grid[player->grid_y - 1][player->grid_x] == 'C')
			map->number_c -= 1;
		map->grid[player->grid_y][player->grid_x] = '0';
		map->grid[player->grid_y - 1][player->grid_x] = 'P';
		player->grid_y -= 1;
		data->count_move += 1;
		print_count_move(data, 0);
		return (1);
	}
	return (0);
}

// 
// This function move the player backward.
// 
int	p_movebackward(t_data *data, t_player *player, t_map *map)
{
	put_tile_to_window(data, player->pos_x, player->pos_y, 3);
	if (map->grid[player->grid_y + 1][player->grid_x] != '1')
	{
		put_tile_to_window(data, player->pos_x, player->pos_y, 2);
		player->pos_y += 64;
		put_tile_to_window(data, player->pos_x, player->pos_y, 3);
		if (map->grid[player->grid_y + 1][player->grid_x] == 'C')
			map->number_c -= 1;
		map->grid[player->grid_y][player->grid_x] = '0';
		map->grid[player->grid_y + 1][player->grid_x] = 'P';
		player->grid_y += 1;
		data->count_move += 1;
		print_count_move(data, 0);
		return (1);
	}
	return (0);
}

// 
// This function move the player on the left.
// 
int	p_moveleft(t_data *data, t_player *player, t_map *map)
{
	put_tile_to_window(data, player->pos_x, player->pos_y, 6);
	if (map->grid[player->grid_y][player->grid_x - 1] != '1')
	{
		put_tile_to_window(data, player->pos_x, player->pos_y, 2);
		player->pos_x -= 64;
		put_tile_to_window(data, player->pos_x, player->pos_y, 6);
		if (map->grid[player->grid_y][player->grid_x - 1] == 'C')
			map->number_c -= 1;
		map->grid[player->grid_y][player->grid_x] = '0';
		map->grid[player->grid_y][player->grid_x - 1] = 'P';
		player->grid_x -= 1;
		data->count_move += 1;
		print_count_move(data, 0);
		return (1);
	}
	return (0);
}

// 
// This function move the player on the right.
// 
int	p_moveright(t_data *data, t_player *player, t_map *map)
{
	put_tile_to_window(data, player->pos_x, player->pos_y, 7);
	if (map->grid[player->grid_y][player->grid_x + 1] != '1')
	{
		put_tile_to_window(data, player->pos_x, player->pos_y, 2);
		player->pos_x += 64;
		put_tile_to_window(data, player->pos_x, player->pos_y, 7);
		if (map->grid[player->grid_y][player->grid_x + 1] == 'C')
			map->number_c -= 1;
		map->grid[player->grid_y][player->grid_x] = '0';
		map->grid[player->grid_y][player->grid_x + 1] = 'P';
		player->grid_x += 1;
		data->count_move += 1;
		print_count_move(data, 0);
		return (1);
	}
	return (0);
}
