/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeisler <ekeisler@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 14:25:38 by ekeisler          #+#    #+#             */
/*   Updated: 2025/01/22 12:51:01 by ekeisler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include "minilibx/mlx.h"
#include "libft/libft.h"
#include <math.h>

typedef struct	s_image_data
{
	void	*addr;
	int		width;
	int		height;
}		t_image_data;

typedef struct	s_data
{
	void		*mlx;
	void		*win;
	t_image_data img;
}		t_data;

typedef struct	s_map
{
	char	**grid;
	int		width;
	int		heiht;	
}		t_map;

void	cleanup(t_data *data);

int			close_window(t_data *data);

#define WINDOW_WIDHT 1920
#define WINDOW_HEIGHT 1080

#endif