/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_rules_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeisler <ekeisler@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 14:26:42 by ekeisler          #+#    #+#             */
/*   Updated: 2025/01/29 15:40:06 by ekeisler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static int	is_rectangular(char **grid, int height)
{
	int	line_lenght;
	int	i;

	if (height <= 0 || !grid || !grid[0])
		return (1);
	line_lenght = ft_strlen(grid[0]);
	i = 1;
	while (i < height)
	{
		if ((int)ft_strlen(grid[i]) != line_lenght)
			return (0);
		i++;
	}
	return (1);
}

static int	surrounded_by_wall(char **grid, int width, int height)
{
	int	x;
	int	y;

	y = 0;
	while (y < height)
	{
		x = 0;
		while (x < width)
		{
			if ((y == 0 || y == height - 1) && grid[y][x] != '1')
				return (0);
			if ((y != 0 && y != height - 1) && (x == 0 || x == width - 1)
				&& grid[y][x] != '1')
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}

static int	map_ressources(char **grid, int width, int height, t_data *data)
{
	int	x, y;
	int	exit;
	int player;

	exit = 0;
	player = 0;
	y = -1;
	while (++y < height)
	{
		x = -1;
		while (++x < width)
		{
			exit += (grid[y][x] == 'E');
			player += (grid[y][x] == 'P');
		}
	}
	if (data->map.number_c < 1)
		print_error_close_game(data, "Error Map : missing collectible");
	if (player == 0)
		print_error_close_game(data, "Error Map : missing player");
	if (exit == 0)
		print_error_close_game(data, "Error Map : missing exit");
	return (exit == 1 && player == 1);
}

void	check_rules_map(t_data *data)
{
	int	x;
	int	y;

	if (data->map.height == 0 || data->map.width == 0)
		print_error_close_game(data, "Error Map : Wrong format (ns)");
	if (!is_rectangular(data->map.grid, data->map.height))
		print_error_close_game(data, "Error Map : Wrong format (nr)");
	if (!surrounded_by_wall(data->map.grid, data->map.width, data->map.height))
		print_error_close_game(data, "Error Map : Wrong format (nsbw)");
	if (!map_ressources(data->map.grid, data->map.width, data->map.height, data))
		print_error_close_game(data, "Error Map : Wrong format (duplicate player or exit)");
	y = 0;
	while (data->map.grid[y])
	{
		x = 0;
		while (data->map.grid[y][x])
		{
			if (data->map.grid[y][x] != '1' && data->map.grid[y][x] != '0' &&
					data->map.grid[y][x] != 'P' && data->map.grid[y][x] != 'E'
						&& data->map.grid[y][x] != 'C')
				print_error_close_game(data, "Error Map : Wrong format");
			x++;
		}
		y++;
	}
}
