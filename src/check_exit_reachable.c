/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_exit_reachable.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeisler <ekeisler@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 10:54:46 by ekeisler          #+#    #+#             */
/*   Updated: 2025/01/30 15:16:55 by ekeisler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

// 
// This function return an error & close the game
// if no path are available for the exit or
// all the collectible cant be obtain.
// 
void	check_exit_reachable(t_data *data)
{
	if (check_path(&data->map))
		ft_putstr_fd("\033[0;32mGood map format !...\n", 1);
	else
		print_error_close_game
			(data, "Collectibles or exit are not reachable...");
}

// 
// This function check if there is a wall in x, y position
// and if we already have visited with the algorithm the
// position we want to visit.
// 
int	is_traversable(t_map *map, int **visited, int x, int y)
{
	return ((x >= 0) && (x < map->width) && (y >= 0)
		&& (y < map->height) && map->grid[y][x] != '1'
		&& !(visited[y][x]));
}
