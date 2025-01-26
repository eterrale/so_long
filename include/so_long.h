/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeisler <ekeisler@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 14:25:38 by ekeisler          #+#    #+#             */
/*   Updated: 2025/01/26 16:40:41 by ekeisler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../minilibx/mlx.h"
# include "../libft/libft.h"
# include <math.h>
# include <unistd.h>

# define NUM_IMG 9

// --------------------------------------- STRUCT 

typedef struct s_player
{
	int	pos_x;
	int	pos_y;
	int	grid_x;
	int	grid_y;	
}	t_player;

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
	int		number_c;
}		t_map;

typedef struct s_data
{
	void			*mlx;
	void			*win;
	int				count_move;
	t_image_data	img[NUM_IMG];
	t_map			map;
	t_player		player;
}		t_data;

// --------------------------------------- UTILS FUNCTIONS

void	print_error(t_data *data);

char	*get_next_line(int fd);

void	put_tile_to_window(t_data *data, int x, int y, int tile);

// --------------------------------------- FREE FUNCTIONS

void	free_map(t_map *map);

int		close_game(t_data *data);

int		free_game(t_data *data);

// --------------------------------------- MAP FUNCTIONS

int		init_ressources(t_data *data);

void	check_rules_map(t_data *data);

int		load_map(const char *filename, t_map *map);

int		load_background(t_data *data);

int		init_window(t_data *data);

int		render_map(t_data *data);

// --------------------------------------- PLAYER MOVE

int		p_moveforward(t_data *data, t_player *player, t_map *map);

int		p_movebackward(t_data *data, t_player *player, t_map *map);

int		p_moveleft(t_data *data, t_player *player, t_map *map);

int		p_moveright(t_data *data, t_player *player, t_map *map);

#endif