/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_hook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeisler <ekeisler@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 17:49:07 by ekeisler          #+#    #+#             */
/*   Updated: 2025/01/29 20:24:07 by ekeisler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"
#include <stdio.h>

static void	move(int key, t_data *data);

int	event_hook(int key, t_data *data)
{
	if (key == 119 || key == 115 || key == 97 || key == 100)
		move(key, data);
	if (key == 0xFF1B)
		close_game(data);
	return (0);
}

static void	move(int key, t_data *data)
{
	if	(key == 119)
		p_moveforward(data, &data->player, &data->map);
	if (key == 115)
		p_movebackward(data, &data->player, &data->map);
	if (key == 97)
		p_moveleft(data, &data->player, &data->map);
	if (key == 100)
		p_moveright(data, &data->player, &data->map);
	if (data->map.number_c == 0)
		put_tile_to_window(data, data->map.exit_x, data->map.exit_y, 8);
}
