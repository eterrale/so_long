/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeisler <ekeisler@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 10:40:11 by ekeisler          #+#    #+#             */
/*   Updated: 2025/01/20 17:30:36 by ekeisler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	cleanup(t_data *data)
{
	if (data->img.addr)
		mlx_destroy_image(data->mlx, data->img.addr);
	if (data->win)
		mlx_destroy_window(data->mlx, data->win);
	mlx_loop_end(data->mlx);
}

int	close_window(t_data *data)
{
	cleanup(data);
	return(0);
}