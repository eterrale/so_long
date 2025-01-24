/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeisler <ekeisler@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 16:00:01 by ekeisler          #+#    #+#             */
/*   Updated: 2025/01/24 04:59:51 by ekeisler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	p_moveforward(t_data *data, t_player *player, t_map *map)
{
	mlx_put_image_to_window(data->mlx, data->win, data->img[5].addr,
		player->posX, player->posY);
	if (map->grid[player->gridY - 1][player->gridX] != '1')
	{
		mlx_put_image_to_window(data->mlx, data->win, data->img[2].addr,
			player->posX, player->posY);
		player->posY -= 64;
		mlx_put_image_to_window(data->mlx, data->win, data->img[5].addr,
			player->posX, player->posY);
		if (map->grid[player->gridY - 1][player->gridX] == 'C')
			map->number_c -= 1;
		map->grid[player->gridY][player->gridX] = '0';
		map->grid[player->gridY - 1][player->gridX] = 'P';
		player->gridY -= 1;
	}
	return (0);
}

int	p_movebackward(t_data *data, t_player *player, t_map *map)
{
	mlx_put_image_to_window(data->mlx, data->win, data->img[3].addr,
		player->posX, player->posY);
	if (map->grid[player->gridY + 1][player->gridX] != '1')
	{
		mlx_put_image_to_window(data->mlx, data->win, data->img[2].addr,
			player->posX, player->posY);
		player->posY += 64;
		mlx_put_image_to_window(data->mlx, data->win, data->img[3].addr,
			player->posX, player->posY);
		if (map->grid[player->gridY + 1][player->gridX] == 'C')
			map->number_c -= 1;
		map->grid[player->gridY][player->gridX] = '0';
		map->grid[player->gridY + 1][player->gridX] = 'P';
		player->gridY += 1;
	}
	return (0);
}

int	p_moveleft(t_data *data, t_player *player, t_map *map)
{
	mlx_put_image_to_window(data->mlx, data->win, data->img[6].addr,
		player->posX, player->posY);
	if (map->grid[player->gridY][player->gridX - 1] != '1')
	{
		mlx_put_image_to_window(data->mlx, data->win, data->img[2].addr,
			player->posX, player->posY);
		player->posX -= 64;
		mlx_put_image_to_window(data->mlx, data->win, data->img[6].addr,
			player->posX, player->posY);
		if (map->grid[player->gridY][player->gridX - 1] == 'C')
			map->number_c -= 1;
		map->grid[player->gridY][player->gridX] = '0';
		map->grid[player->gridY][player->gridX - 1] = 'P';
		player->gridX -= 1;
	}
	return (0);
}

int	p_moveright(t_data *data, t_player *player, t_map *map)
{
	mlx_put_image_to_window(data->mlx, data->win, data->img[7].addr,
		player->posX, player->posY);
	if (map->grid[player->gridY][player->gridX + 1] != '1')
	{
		mlx_put_image_to_window(data->mlx, data->win, data->img[2].addr,
			player->posX, player->posY);
		player->posX += 64;
		mlx_put_image_to_window(data->mlx, data->win, data->img[7].addr,
			player->posX, player->posY);
		if (map->grid[player->gridY][player->gridX + 1] == 'C')
			map->number_c -= 1;
		map->grid[player->gridY][player->gridX] = '0';
		map->grid[player->gridY][player->gridX + 1] = 'P';
		player->gridX += 1;
	}
	return (0);
}
