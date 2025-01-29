/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_rules_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeisler <ekeisler@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 14:26:42 by ekeisler          #+#    #+#             */
/*   Updated: 2025/01/29 14:29:44 by ekeisler         ###   ########.fr       */
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

void	check_rules_map(t_data *data)
{
	int	x;
	int	y;

	if (data->map.height == 0 || data->map.width == 0)
		print_error_close_game(data, "Error Map : Wrong format");
	if (!is_rectangular(data->map.grid, data->map.height))
		print_error_close_game(data, "Error Map : Wrong format");
	y = 0;
	while (data->map.grid[y])
	{
		x = 0;
		while (data->map.grid[y][x])
		{
			if (data->map.grid[y][x] != '1' && data->map.grid[y][x] != '0' &&
					data->map.grid[y][x] != 'P' && data->map.grid[y][x] != 'E'
						&& data->map.grid[y][x] != 'C')
				print_error("Error Map : Wrong format");
			x++;
		}
		y++;
	}
}
