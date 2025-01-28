/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeisler <ekeisler@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 19:27:24 by ekeisler          #+#    #+#             */
/*   Updated: 2025/01/28 13:40:20 by ekeisler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	init_window(t_data *data, char *map_path)
{
	t_map	map;
	int window_width;
	int window_height;

	load_map(map_path, &map);
	data->map = map;
	data->mlx = mlx_init();
	window_width = data->map.width * 64;
    window_height = data->map.height * 64;
    if (window_width > 1920)
        window_width = 1920;
    if (window_height > 1080)
        window_height = 1080;
    data->win = mlx_new_window(data->mlx, window_width, window_height, "PURE IT");
	init_ressources(data);
	load_background(data);
	render_map(data);
	ft_putstr_fd("start game...\n", 1);
	return (0);
}
