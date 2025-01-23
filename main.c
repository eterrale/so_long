/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeisler <ekeisler@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 17:37:33 by ekeisler          #+#    #+#             */
/*   Updated: 2025/01/22 19:43:11 by ekeisler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_hook(int key, t_data *data)
{
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
