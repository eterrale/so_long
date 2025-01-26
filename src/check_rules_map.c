/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_rules_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeisler <ekeisler@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 14:26:42 by ekeisler          #+#    #+#             */
/*   Updated: 2025/01/26 14:58:37 by ekeisler         ###   ########.fr       */
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
	if (!is_rectangular(data->map.grid, data->map.height))
			print_error(data);
}