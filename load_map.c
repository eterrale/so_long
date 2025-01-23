/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeisler <ekeisler@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 12:51:15 by ekeisler          #+#    #+#             */
/*   Updated: 2025/01/23 12:54:27 by ekeisler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <fcntl.h>

static void	size_map(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (map->grid[i])
	{
		j = 0;
		while (map->grid[i][j])
			j++;
		i++;
	}
	map->height = i;
	map->width = j;
}

int	load_map(const char *filename, t_map *map)
{
	int		fd;
	char	*buf;
	char	*line;
	char	*temp;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (-1);
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
	size_map(map);
	return (0);
}
