/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeisler <ekeisler@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 19:27:24 by ekeisler          #+#    #+#             */
/*   Updated: 2025/01/22 19:40:25 by ekeisler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	init_window(t_data *data)
{
	t_map	map;

	load_map("map/map.ber", &map);
	data->map = map;
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, 960, 540, "PURE IT");
	load_background(data);
	return (0);
}
