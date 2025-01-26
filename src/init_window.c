/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeisler <ekeisler@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 19:27:24 by ekeisler          #+#    #+#             */
/*   Updated: 2025/01/26 14:58:55 by ekeisler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	init_window(t_data *data)
{
	t_map	map;

	load_map("map/map.ber", &map);
	data->map = map;
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, data->map.width * 64, data->map.height * 64, "PURE IT");
	init_ressources(data);
	load_background(data);
	render_map(data);
	return (0);
}
