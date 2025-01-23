/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeisler <ekeisler@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 16:00:01 by ekeisler          #+#    #+#             */
/*   Updated: 2025/01/23 16:25:23 by ekeisler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	p_moveforward(t_data *data)
{
	mlx_put_image_to_window(data->mlx, data->win, data->img[2].addr,
		data->player.posX, data->player.posY);
	data->player.posY -= 32;
	mlx_put_image_to_window(data->mlx, data->win, data->img[5].addr,
		data->player.posX, data->player.posY);
	return (0);
}

int	p_movebackward(t_data *data)
{
	mlx_put_image_to_window(data->mlx, data->win, data->img[2].addr,
		data->player.posX, data->player.posY);
	data->player.posY += 32;
	mlx_put_image_to_window(data->mlx, data->win, data->img[3].addr,
		data->player.posX, data->player.posY);
	return (0);
}

int	p_moveleft(t_data *data)
{
	mlx_put_image_to_window(data->mlx, data->win, data->img[2].addr,
		data->player.posX, data->player.posY);
	data->player.posX -= 32;
	mlx_put_image_to_window(data->mlx, data->win, data->img[6].addr,
		data->player.posX, data->player.posY);
	return (0);
}

int	p_moveright(t_data *data)
{
	mlx_put_image_to_window(data->mlx, data->win, data->img[2].addr,
		data->player.posX, data->player.posY);
	data->player.posX += 32;
	mlx_put_image_to_window(data->mlx, data->win, data->img[7].addr,
		data->player.posX, data->player.posY);
	return (0);
}
