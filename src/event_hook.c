/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_hook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeisler <ekeisler@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 17:49:07 by ekeisler          #+#    #+#             */
/*   Updated: 2025/01/30 18:30:54 by ekeisler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	move(int key, t_data *data);
static int	player_is_on_exit(t_data *data);
static void	player_move_on_exit(t_data *d, int key);

// 
// This function hold all the event we hook when a key is pressed
// in game.
// 
int	event_hook(int key, t_data *data)
{
	if (key == 119 || key == 115 || key == 97 || key == 100)
		move(key, data);
	if (player_is_on_exit(data) && data->map.number_c == 0)
		print_count_move(data, 1);
	if (key == 0xFF1B)
		close_game(data);
	return (0);
}

// 
// This function apply the movement of the player and
// also check if he is moving on the exit tile
// 
static void	move(int key, t_data *data)
{
	if (key == 119)
	{
		p_moveforward(data, &data->player, &data->map);
		player_move_on_exit(data, key);
	}
	if (key == 115)
	{
		p_movebackward(data, &data->player, &data->map);
		player_move_on_exit(data, key);
	}
	if (key == 97)
	{
		p_moveleft(data, &data->player, &data->map);
		player_move_on_exit(data, key);
	}
	if (key == 100)
	{
		p_moveright(data, &data->player, &data->map);
		player_move_on_exit(data, key);
	}
}

// 
// This function purpose is to check if the player 
// is on the exit
// 
static int	player_is_on_exit(t_data *data)
{
	if ((data->player.pos_x == data->map.exit_x)
		&& (data->player.pos_y == data->map.exit_y))
		return (1);
	return (0);
}

// 
// This function is to hold when the player
// is moving on the exit.
// 
static void	player_move_on_exit(t_data *d, int key)
{
	static int	exit_rendered = 0;

	if (player_is_on_exit(d))
	{
		if (key == 119)
			put_tile_to_window(d, d->player.pos_x, d->player.pos_y, 11);
		if (key == 115)
			put_tile_to_window(d, d->player.pos_x, d->player.pos_y, 10);
		if (key == 97)
			put_tile_to_window(d, d->player.pos_x, d->player.pos_y, 12);
		if (key == 100)
			put_tile_to_window(d, d->player.pos_x, d->player.pos_y, 13);
		exit_rendered = 0;
	}
	else if (!player_is_on_exit(d) && d->map.number_c != 0
		&& exit_rendered == 0)
	{
		put_tile_to_window(d, d->map.exit_x, d->map.exit_y, 9);
		exit_rendered = 1;
	}
	else if (!player_is_on_exit(d) && d->map.number_c == 0)
	{
		put_tile_to_window(d, d->map.exit_x, d->map.exit_y, 8);
		exit_rendered = 1;
	}
}
