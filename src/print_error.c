/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeisler <ekeisler@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 14:19:38 by ekeisler          #+#    #+#             */
/*   Updated: 2025/01/28 13:44:39 by ekeisler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	print_error_close_game(t_data *data)
{
	ft_putstr_fd("Error\n", 1);
	close_game(data);
	free_game(data);
	exit(1);
}

void	print_error(void)
{
	ft_putstr_fd("Error\n", 1);
	exit(1);
}
