/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeisler <ekeisler@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 17:37:33 by ekeisler          #+#    #+#             */
/*   Updated: 2025/01/30 18:30:45 by ekeisler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

// 
// Main function that collect our map path data to launch
// the program
// 
int	main(int argc, char **argv)
{
	t_data	data;

	if (argc > 2 || !argv[1])
		print_error_exit("wrong path or too many arguments...");
	init_program(&data, argv[1]);
	if (data.mlx)
	{
		mlx_hook(data.win, 17, 0, close_game, &data);
		mlx_hook(data.win, 2, 1L << 0, event_hook, &data);
		mlx_loop(data.mlx);
	}
	return (0);
}
