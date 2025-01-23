/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ressources.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeisler <ekeisler@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 20:26:51 by ekeisler          #+#    #+#             */
/*   Updated: 2025/01/22 20:30:34 by ekeisler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	init_ressources(t_data *data)
{
	int i;
	
	i = 0;
	data->img[0].addr = mlx_xpm_file_to_image(data->mlx, "ressources/background.xpm",
			&data->img[0].width, &data->img[0].height);
	data->img[1].addr = mlx_xpm_file_to_image(data->mlx, "ressources/env/Bush.xpm",
			&data->img[1].width, &data->img[1].height);
	data->img[2].addr = mlx_xpm_file_to_image(data->mlx, "ressources/env/Floor.xpm",
			&data->img[2].width, &data->img[2].height);
	while (i < 3)
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
