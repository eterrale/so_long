/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_count_move.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeisler <ekeisler@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 18:01:47 by ekeisler          #+#    #+#             */
/*   Updated: 2025/01/29 18:13:04 by ekeisler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	print_count_move(t_data *data)
{
	char	*str;

	str = ft_itoa(data->count_move);
	ft_putstr_fd("\033[0;36mMoves count : \033[1;33m", 1);
	ft_putstr_fd(str, 1);
	ft_putstr_fd("\n", 1);
	free(str);
}