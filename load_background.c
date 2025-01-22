/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_background.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeisler <ekeisler@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 19:31:47 by ekeisler          #+#    #+#             */
/*   Updated: 2025/01/22 19:40:47 by ekeisler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	load_background(t_data *data)
{
	data->img[0].addr = mlx_xpm_file_to_image(data->mlx, "ressources/test.xpm",
			&data->img[0].width, &data->img[0].height);
	if (!data->img[0].addr)
	{
		ft_putstr_fd("Error rendering background\n", 1);
		return (-1);
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img[0].addr, 0, 0);
	return (0);
}
