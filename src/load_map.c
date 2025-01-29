/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeisler <ekeisler@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 12:51:15 by ekeisler          #+#    #+#             */
/*   Updated: 2025/01/29 15:29:38 by ekeisler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"
#include <fcntl.h>

static void	check_size_and_rules_map(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map.grid[i])
	{
		j = 0;
		while (data->map.grid[i][j])
			j++;
		i++;
	}
	data->map.height = i;
	data->map.width = j;
	count_collectible(&data->map);
	check_rules_map(data);
	check_exit_reachable(data);
}

int	load_map(const char *filename, t_map *map, t_data *data)
{
	int		fd;
	char	*buf;
	char	*line;
	char	*temp;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		print_error("File Error : reading map file...");
	buf = ft_strdup("");
	line = get_next_line(fd);
	while (line)
	{
		temp = ft_strjoin(buf, line);
		free(buf);
		free(line);
		if (!temp)
			return (close(fd), -1);
		buf = temp;
		line = get_next_line(fd);
	}
	close(fd);
	map->grid = ft_split(buf, '\n');
	free(buf);
	check_size_and_rules_map(data);
	return (0);
}

int	count_collectible(t_map *map)
{
	int	x;
	int	y;

	y = 0;
	while (map->grid[y])
	{
		x = 0;
		while (map->grid[y][x])
		{
			if (map->grid[y][x] == 'C')
				map->number_c++;
			x++;
		}
		y++;
	}
	return (0);
}
