/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeisler <ekeisler@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 14:25:38 by ekeisler          #+#    #+#             */
/*   Updated: 2025/01/22 20:45:29 by ekeisler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "minilibx/mlx.h"
# include "libft/libft.h"
# include <math.h>
# include <unistd.h>

# define NUM_IMG 3

// --------------------------------------- STRUCT 

typedef struct s_image_data
{
	void	*addr;
	int		width;
	int		height;
}		t_image_data;

typedef struct s_map
{
	char	**grid;
	int		width;
	int		height;	
}		t_map;

typedef struct s_data
{
	void			*mlx;
	void			*win;
	t_image_data	img[NUM_IMG];
	t_map			map;
}		t_data;

// --------------------------------------- UTILS FUNCTIONS

char	*get_next_line(int fd);

// --------------------------------------- FREE FUNCTIONS

void	free_map(t_map *map);

int		close_game(t_data *data);

int		free_game(t_data *data);

// --------------------------------------- MAP FUNCTIONS

int		init_ressources(t_data *data);

int		load_map(const char *filename, t_map *map);

int		load_background(t_data *data);

int		init_window(t_data *data);

void 	render_map(t_data *data);

#endif