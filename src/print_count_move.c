/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_count_move.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeisler <ekeisler@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 18:01:47 by ekeisler          #+#    #+#             */
/*   Updated: 2025/01/30 15:35:03 by ekeisler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

// 
// This function print on our terminal
// the count of our moves, if the player
// end the game it will print a congratulation
// message.
// 
void	print_count_move(t_data *data, int i)
{
	char	*str;

	str = ft_itoa(data->count_move);
	if (i == 0)
	{
		ft_putstr_fd("\033[0;36mMoves count : \033[1;33m", 1);
		ft_putstr_fd(str, 1);
		ft_putstr_fd("\n", 1);
	}
	else
	{
		ft_putstr_fd("\033[0;32m\nCongratulation ! You won with \033[1;33m", 1);
		ft_putstr_fd(str, 1);
		ft_putstr_fd("\033[0;32m moves !\n", 1);
		ft_putstr_fd("\n", 1);
		free(str);
		close_game(data);
	}
	free(str);
}
