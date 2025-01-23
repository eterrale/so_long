/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ressources.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeisler <ekeisler@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 20:26:51 by ekeisler          #+#    #+#             */
/*   Updated: 2025/01/23 14:40:26 by ekeisler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	init_ressources(t_data *data)
{
	int i;
	
	i = 0;
	data->img[0].addr = mlx_xpm_file_to_image(data->mlx, "ressources/background.xpm",
			&data->img[0].width, &data->img[0].height);
	data->img[1].addr = mlx_xpm_file_to_image(data->mlx, "ressources/env/Tree.xpm",
			&data->img[1].width, &data->img[1].height);
	data->img[2].addr = mlx_xpm_file_to_image(data->mlx, "ressources/env/Floor.xpm",
			&data->img[2].width, &data->img[2].height);
	data->img[3].addr = mlx_xpm_file_to_image(data->mlx, "ressources/character/Bunny0.xpm",
			&data->img[3].width, &data->img[3].height);
	data->img[4].addr = mlx_xpm_file_to_image(data->mlx, "ressources/cosm/garbage.xpm",
			&data->img[4].width, &data->img[4].height);
	// data->img[5].addr = mlx_xpm_file_to_image(data->mlx, "ressources/character/Bunny1.xpm",
	// 		&data->img[5].width, &data->img[5].height);
	// data->img[6].addr = mlx_xpm_file_to_image(data->mlx, "ressources/character/Bunny2.xpm",
	// 		&data->img[6].width, &data->img[6].height);
	// data->img[7].addr = mlx_xpm_file_to_image(data->mlx, "ressources/character/Bunny3.xpm",
	// 		&data->img[7].width, &data->img[7].height);
	while (i <= NUM_IMG)
	{
		if (!data->img[i].addr)
		{
			ft_putstr_fd("Error init ressources...", 1);
			exit(1);
		}
		i++;
	}
	return (0);
}
