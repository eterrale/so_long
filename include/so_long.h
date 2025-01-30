/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeisler <ekeisler@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 14:25:38 by ekeisler          #+#    #+#             */
/*   Updated: 2025/01/30 15:39:15 by ekeisler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../minilibx/mlx.h"
# include "../libft/libft.h"
# include <unistd.h>

# define NUM_IMG 14

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
	int		exit_x;
	int		exit_y;
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

void	print_error_exit(char *error_id);

void	print_error_close_game(t_data *data, char *error_id);

void	print_count_move(t_data *data, int i);

char	*get_next_line(int fd);

void	put_tile_to_window(t_data *data, int x, int y, int tile);

// --------------------------------------- FREE FUNCTIONS

void	free_map(t_map *map);

int		close_game(t_data *data);

// --------------------------------------- MAP FUNCTIONS

void	check_map_ext(const char *filename);

int		check_path(t_map *map);

void	check_exit_reachable(t_data *data);

int		is_traversable(t_map *map, int **visited, int x, int y);

int		init_ressources(t_data *data);

void	check_rules_map(t_data *d);

int		parse_map(const char *filename, t_map *map, t_data *data);

int		init_program(t_data *data, char *map_path);

int		render_map(t_data *data);

// --------------------------------------- PLAYER MOVE

int		p_moveforward(t_data *data, t_player *player, t_map *map);

int		p_movebackward(t_data *data, t_player *player, t_map *map);

int		p_moveleft(t_data *data, t_player *player, t_map *map);

int		p_moveright(t_data *data, t_player *player, t_map *map);

int		event_hook(int key, t_data *data);

#endif