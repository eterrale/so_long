/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeisler <ekeisler@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 14:19:38 by ekeisler          #+#    #+#             */
/*   Updated: 2025/01/30 15:39:06 by ekeisler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

// 
// This function print an error message
// then close the game
// 
void	print_error_close_game(t_data *data, char *error_id)
{
	ft_putstr_fd("\033[1;31mError\n", 2);
	ft_putstr_fd(error_id, 2);
	ft_putstr_fd("\n", 2);
	ft_putstr_fd("\033[0m", 2);
	close_game(data);
	exit(1);
}

// 
// This function print an error message
// then exit the program instanly in 
// case we have nothing to destroy or free
// 
void	print_error_exit(char *error_id)
{
	ft_putstr_fd("\033[1;31mError\n", 2);
	ft_putstr_fd(error_id, 2);
	ft_putstr_fd("\n", 2);
	ft_putstr_fd("\033[0m", 2);
	exit(1);
}
