/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_path.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeisler <ekeisler@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 14:14:33 by ekeisler          #+#    #+#             */
/*   Updated: 2025/01/28 20:25:53 by ekeisler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	check_map_path(const char *filename)
{
	int	size;

	size = ft_strlen(filename);
	if (filename[size - 4] != '.')
		print_error("Map Error : Wrong extension");
	if (filename[size - 3] != 'b')
		print_error("Map Error : Wrong extension");
	if (filename[size - 2] != 'e')
		print_error("Map Error : Wrong extension");
	if (filename[size - 1] != 'r')
		print_error("Map Error : Wrong extension");
}
