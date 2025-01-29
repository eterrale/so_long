/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_exit_reachable.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeisler <ekeisler@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 10:54:46 by ekeisler          #+#    #+#             */
/*   Updated: 2025/01/29 14:34:46 by ekeisler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	free_visited(int **visited, int height)
{
	int	i;

	i = 0;
	while (i < height)
	{
		free(visited[i]);
		i++;
	}
	free(visited);
}

void	check_exit_reachable(t_data *data)
{
	if (check_path(&data->map))
		ft_putstr_fd("\033[0;32mGood map format !...\n", 1);
	else
		print_error_close_game(data, "Error : Bad map format");
}
