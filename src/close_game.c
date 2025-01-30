/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeisler <ekeisler@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 20:26:14 by ekeisler          #+#    #+#             */
/*   Updated: 2025/01/30 18:30:57 by ekeisler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	destroy_and_free(t_data *data);

// 
// This function close the game
// 
int	close_game(t_data *data)
{
	if (data->mlx)
		mlx_loop_end(data->mlx);
	destroy_and_free(data);
	ft_putstr_fd("\033[0;32m", 1);
	ft_putstr_fd("closing game...\n\033[0m", 1);
	exit(0);
	return (0);
}

// 
// This function destroy and free all
// allocated elements of the program
// 
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
	if (data->mlx)
		mlx_destroy_display(data->mlx);
	free_map(&data->map);
	if (data->mlx)
		free(data->mlx);
	ft_putstr_fd("\033[0;35m", 1);
	ft_putstr_fd("free all variables..\n", 1);
	ft_putstr_fd("\033[0m", 1);
}

// 
// This function free our map grid 
// one by one
// 
void	free_map(t_map *map)
{
	int	x;

	x = 0;
	while (map->grid[x])
	{
		free(map->grid[x]);
		x++;
	}
	free(map->grid);
}
