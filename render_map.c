/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeisler <ekeisler@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 20:20:06 by ekeisler          #+#    #+#             */
/*   Updated: 2025/01/23 14:41:17 by ekeisler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int render_map(t_data *data)
{
    int x;
    int y;
    int i;
    int j;
    
    y = 0;
    i = 0;
    while (data->map.grid[i])
    {
        x = 0;
        j = 0;
        while (data->map.grid[i][j] != '\0')
        {
            mlx_put_image_to_window(data->mlx, data->win, data->img[2].addr, x, y);
            if (data->map.grid[i][j] == '1')
                mlx_put_image_to_window(data->mlx, data->win, data->img[1].addr, x, y);
            if (data->map.grid[i][j] == 'P')
                mlx_put_image_to_window(data->mlx, data->win, data->img[3].addr, x, y);
            if (data->map.grid[i][j] == 'C')
                mlx_put_image_to_window(data->mlx, data->win, data->img[4].addr, x, y);
            x += 32;
            j++;
        }
        y += 32;
        i++;
    }
    return (0);
}
