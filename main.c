/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeisler <ekeisler@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 17:37:33 by ekeisler          #+#    #+#             */
/*   Updated: 2025/01/20 17:32:18 by ekeisler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

int	key_hook(int key, t_data *data)
{
	printf("Bang! key = %d\n", key);
  	if (key==0xFF1B)
		close_window(data);
	return (0);
}

int	mouse_hook(int key)
{
	printf("Baw! key = %d\n", key);
	return (0);
}
int	main(void)
{
	t_data	win;
	
	win.mlx = mlx_init();
	win.win = mlx_new_window(win.mlx, WINDOW_WIDHT, WINDOW_HEIGHT, "so_long");
	win.img.addr = mlx_xpm_file_to_image(win.mlx, "ressources/test.xpm", &win.img.width, &win.img.height);
	if (!win.img.addr)
	{
		printf("ERRORRRRR");
		return (1);
	}
	mlx_put_image_to_window(win.mlx, win.win, win.img.addr, 0, 0);
	mlx_hook(win.win, 17, 0, close_window, &win);
	mlx_key_hook(win.win, key_hook, &win);
	mlx_mouse_hook(win.win, mouse_hook, &win);
	mlx_loop(win.mlx);
	mlx_destroy_display(win.mlx);
	free(win.mlx);
	return (0);
}
