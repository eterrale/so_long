/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_exit_reachable_utils.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeisler <ekeisler@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 20:11:55 by ekeisler          #+#    #+#             */
/*   Updated: 2025/01/29 14:36:10 by ekeisler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"
#include <stdio.h>

static int	is_traversable(t_map *map, int **visited, int x, int y)
{
	return ((x >= 0) && (x < map->width) && (y >= 0)
		&& (y < map->height) && map->grid[y][x] != '1'
		&& !(visited[y][x]));
}

static int	dfs(t_map *map, int **visited, int x, int y)
{
	static int	collectables = 0;
	static int	exit_found = 0;

	visited[y][x] = 1;
	if (map->grid[y][x] == 'C')
		collectables++;
	if (map->grid[y][x] == 'E')
		exit_found++;
	if (is_traversable(map, visited, x - 1, y))
		dfs(map, visited, x - 1, y);
	if (is_traversable(map, visited, x + 1, y))
		dfs(map, visited, x + 1, y);
	if (is_traversable(map, visited, x, y - 1))
		dfs(map, visited, x, y - 1);
	if (is_traversable(map, visited, x, y + 1))
		dfs(map, visited, x, y + 1);
	if (collectables == map->number_c && exit_found == 1)
		return (1);
	return (0);
}

int	check_path(t_map *map)
{
	int		**visited;
	int		x;
	int		y;
	int		bool;

	bool = 0;
	x = 0;
	y = 0;
	visited = allocate_visited(map);
	if (!visited)
		return (0);
	find_start(map, &x, &y);
	bool = dfs(map, visited, x, y);
	free_visited(visited, map->height);
	return (bool);
}

int	**allocate_visited(t_map *map)
{
	int	**visited;
	int	i;

	visited = malloc(sizeof(int *) * map->height);
	if (!visited)
		print_error("Error : Could not allocate memory");
	i = 0;
	while (i < map->height)
	{
		visited[i] = malloc(sizeof(int) * map->width);
		if (!visited[i])
			print_error("Error : Could not allocate memory");
		ft_bzero(visited[i], sizeof(int) * map->width);
		i++;
	}
	return (visited);
}

void	find_start(t_map *map, int *x, int *y)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			if (map->grid[i][j] == 'P')
			{
				*x = j;
				*y = i;
			}
			j++;
		}
		i++;
	}
}
