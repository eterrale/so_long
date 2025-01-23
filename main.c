/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeisler <ekeisler@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 17:37:33 by ekeisler          #+#    #+#             */
/*   Updated: 2025/01/23 16:14:10 by ekeisler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_hook(int key, t_data *data)
{
	if (key == 119)
		p_moveforward(data);
	if (key == 115)
		p_movebackward(data);
	if (key == 97)
		p_moveleft(data);
	if (key == 100)
		p_moveright(data);
	if (key == 0xFF1B)
		close_game(data);
	return (0);
}

int	main(void)
{
	t_data	data;

	init_window(&data);
	mlx_hook(data.win, 17, 0, close_game, &data);
	mlx_key_hook(data.win, key_hook, &data);
	mlx_loop(data.mlx);
	free_game(&data);
	return (0);
}
