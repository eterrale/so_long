/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeisler <ekeisler@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 19:27:24 by ekeisler          #+#    #+#             */
/*   Updated: 2025/01/29 14:32:02 by ekeisler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	init_window(t_data *data, char *map_path)
{
	int	window_width;
	int	window_height;

	ft_bzero(data, sizeof(t_data));
	check_map_ext(map_path);
	load_map(map_path, &data->map, data);
	count_collectible(&data->map);
	check_exit_reachable(data);
	data->mlx = mlx_init();
	init_ressources(data);
	window_width = data->map.width * 64;
	window_height = data->map.height * 64;
	if (window_width > 3840 || window_height > 2160)
		print_error_close_game(data, "Map Error : oversized map");
	data->win = mlx_new_window(data->mlx, window_width,
			window_height, "PURE IT");
	render_map(data);
	ft_putstr_fd("\033[0;34mstart game...\n\033[0;32m", 1);
	return (0);
}
