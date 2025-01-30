/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ressources.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeisler <ekeisler@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 20:26:51 by ekeisler          #+#    #+#             */
/*   Updated: 2025/01/30 18:30:48 by ekeisler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	put_xpm_addr(t_data *data, int i, char *path);
static void	check_image_addr(t_data *data);

// 
// This function initialize all the address of our assets.
// 
int	init_ressources(t_data *data)
{
	put_xpm_addr(data, 0, "ressources/background.xpm");
	put_xpm_addr(data, 1, "ressources/env/Tree.xpm");
	put_xpm_addr(data, 2, "ressources/env/Floor.xpm");
	put_xpm_addr(data, 3, "ressources/character/Bunny0.xpm");
	put_xpm_addr(data, 4, "ressources/col/carrot.xpm");
	put_xpm_addr(data, 5, "ressources/character/Bunny1.xpm");
	put_xpm_addr(data, 6, "ressources/character/Bunny2.xpm");
	put_xpm_addr(data, 7, "ressources/character/Bunny3.xpm");
	put_xpm_addr(data, 8, "ressources/env/exit.xpm");
	put_xpm_addr(data, 9, "ressources/env/exit2.xpm");
	put_xpm_addr(data, 10, "ressources/character/Bunny4.xpm");
	put_xpm_addr(data, 11, "ressources/character/Bunny5.xpm");
	put_xpm_addr(data, 12, "ressources/character/Bunny6.xpm");
	put_xpm_addr(data, 13, "ressources/character/Bunny7.xpm");
	check_image_addr(data);
	return (0);
}

// 
// This function initialize one asset.
// 
static void	put_xpm_addr(t_data *data, int i, char *path)
{
	data->img[i].addr = mlx_xpm_file_to_image(data->mlx, path,
			&data->img[i].width, &data->img[i].height);
}

// 
// This function check if one of our initialization
// have failed and return an error if so.
// 
static void	check_image_addr(t_data *data)
{
	int	i;

	i = 0;
	while (i < NUM_IMG)
	{
		if (!data->img[i].addr)
			print_error_close_game
				(data, "could not initialize ressources...");
		i++;
	}
}
