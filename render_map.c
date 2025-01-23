/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeisler <ekeisler@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 20:20:06 by ekeisler          #+#    #+#             */
/*   Updated: 2025/01/22 20:45:59 by ekeisler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void render_map(t_data *data)
{
    int x, y;

    for (y = 0; y < data->map.height; y++)
    {
        for (x = 0; x < data->map.width; x++)
        {
            void *img = NULL;
            if (data->map.grid[y][x] == '1')
                img = data->img[1].addr;
            else if (data->map.grid[y][x] == '0')
                img = data->img[2].addr;
            if (img)
                mlx_put_image_to_window(data->mlx, data->win, img, x * 960, y * 540);
        }
    }
}