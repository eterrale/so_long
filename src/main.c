/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeisler <ekeisler@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 17:37:33 by ekeisler          #+#    #+#             */
/*   Updated: 2025/01/28 13:44:30 by ekeisler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"
#include <stdio.h>

int	key_hook(int key, t_data *data)
{
	if (key == 119)
	{
		p_moveforward(data, &data->player, &data->map);
		data->count_move += 1;
	}
	if (key == 115)
	{
		p_movebackward(data, &data->player, &data->map);
		data->count_move += 1;
	}
	if (key == 97)
	{
		p_moveleft(data, &data->player, &data->map);
		data->count_move += 1;
	}
	if (key == 100)
	{
		p_moveright(data, &data->player, &data->map);
		data->count_move += 1;
	}
	if (key == 0xFF1B)
		close_game(data);
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	data;
	
	if(argc > 2 || !argv[1])
		print_error();
	init_window(&data, argv[1]);
	if (data.mlx)
	{
		mlx_hook(data.win, 17, 0, close_game, &data);
		mlx_key_hook(data.win, key_hook, &data);
		mlx_loop(data.mlx);
	}
	free_game(&data);
	return (0);
}
