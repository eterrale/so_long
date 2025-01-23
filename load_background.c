/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_background.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeisler <ekeisler@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 19:31:47 by ekeisler          #+#    #+#             */
/*   Updated: 2025/01/22 20:28:24 by ekeisler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	load_background(t_data *data)
{
	mlx_put_image_to_window(data->mlx, data->win, data->img[0].addr, 0, 0);
	return (0);
}
