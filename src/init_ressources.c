/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ressources.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeisler <ekeisler@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 20:26:51 by ekeisler          #+#    #+#             */
/*   Updated: 2025/01/26 16:20:46 by ekeisler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static const char	**img_paths(void)
{
	static const char	*img_paths[NUM_IMG] = {
		"ressources/background.xpm",
		"ressources/env/Tree.xpm",
		"ressources/env/Floor.xpm",
		"ressources/character/Bunny0.xpm",
		"ressources/cosm/garbage.xpm",
		"ressources/character/Bunny1.xpm",
		"ressources/character/Bunny2.xpm",
		"ressources/character/Bunny3.xpm",
		"ressources/env/exit.xpm"
	};

	return (img_paths);
}

int	init_ressources(t_data *data)
{
	int			i;
	const char	**paths;

	i = 0;
	paths = img_paths();
	while (i < NUM_IMG)
	{
		data->img[i].addr = mlx_xpm_file_to_image(data->mlx, (char *)paths[i],
				&data->img[i].width, &data->img[i].height);
		if (!data->img[i].addr)
			print_error(data);
		i++;
	}
	return (0);
}
