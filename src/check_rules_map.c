/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_rules_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeisler <ekeisler@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 14:26:42 by ekeisler          #+#    #+#             */
/*   Updated: 2025/02/13 15:08:07 by ekeisler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static int	is_rectangular(char **grid, int height);
static int	surrounded_by_wall(char **grid, int width, int height);
static int	map_ressources(char **grid, int width, int height, t_data *data);

// 
// This function check our map respect all the rules
// prescribed by the subject.
// 
void	check_rules_map(t_data *d)
{
	int	x;
	int	y;

	if (d->map.height == 0 || d->map.width == 0)
		print_error_close_game(d, "wrong format (ns)");
	if (!is_rectangular(d->map.grid, d->map.height))
		print_error_close_game(d, "wrong format (nr)");
	if (!surrounded_by_wall(d->map.grid, d->map.width, d->map.height))
		print_error_close_game(d, "wrong format (nsbw)");
	if (!map_ressources(d->map.grid, d->map.width, d->map.height, d))
		print_error_close_game(d, "wrong format (duplicate player or exit)");
	y = 0;
	while (d->map.grid[y])
	{
		x = 0;
		while (d->map.grid[y][x])
		{
			if (d->map.grid[y][x] != '1' && d->map.grid[y][x] != '0' &&
					d->map.grid[y][x] != 'P' && d->map.grid[y][x] != 'E'
						&& d->map.grid[y][x] != 'C')
				print_error_close_game(d, "wrong format");
			x++;
		}
		y++;
	}
}

// 
// This function check is our map is
// rectangular.
// 
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

// 
// This function check if our map is
// surrounded by wall.
// 
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

// 
// This function check if the map miss mandatory
// elements (ex: one and only one player, same for number of exit...)
// 
static int	map_ressources(char **grid, int width, int height, t_data *data)
{
	int	x;
	int	y;
	int	exit;
	int	player;

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
		print_error_close_game(data, "missing collectible");
	if (player == 0)
		print_error_close_game(data, "missing player");
	if (exit == 0)
		print_error_close_game(data, "missing exit");
	return (exit == 1 && player == 1);
}
