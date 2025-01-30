/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_ext.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeisler <ekeisler@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 14:14:33 by ekeisler          #+#    #+#             */
/*   Updated: 2025/01/30 15:41:25 by ekeisler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

// 
// This function return an error if the filename dont
// have the exension we needed. we only want to read .ber files extension.
// 
void	check_map_ext(const char *filename)
{
	int	size;

	size = ft_strlen(filename);
	if (filename[size - 4] != '.')
		print_error_exit("wrong file extension...");
	if (filename[size - 3] != 'b')
		print_error_exit("wrong file extension...");
	if (filename[size - 2] != 'e')
		print_error_exit("wrong file extension...");
	if (filename[size - 1] != 'r')
		print_error_exit("wrong file extension...");
}
