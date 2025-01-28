/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_rules_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeisler <ekeisler@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 14:26:42 by ekeisler          #+#    #+#             */
/*   Updated: 2025/01/28 13:45:25 by ekeisler         ###   ########.fr       */
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
	int	i;

	i = 0;
	if (data->map.height == 0 || data->map.width == 0)
		print_error_close_game(data);
	if (!is_rectangular(data->map.grid, data->map.height))
		print_error_close_game(data);
	while (i < data->map.height)
	{
		if ((data->map.grid[i][0] != '1')
			|| (data->map.grid[i][data->map.width - 1] != '1'))
			print_error_close_game(data);
		i++;
	}
}
