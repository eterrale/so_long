/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeisler <ekeisler@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 15:12:26 by ekeisler          #+#    #+#             */
/*   Updated: 2024/11/21 14:33:34 by ekeisler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdint.h>

void	*ft_calloc(size_t nmeb, size_t size)
{
	unsigned char	*res;
	unsigned char	*cpy;
	size_t			total_size;

	if (nmeb != 0 && size > SIZE_MAX / nmeb)
		return (NULL);
	total_size = nmeb * size;
	res = malloc(total_size);
	cpy = (unsigned char *)res;
	if (res == NULL)
		return (NULL);
	while (total_size > 0)
	{
		*cpy = 0;
		total_size--;
		cpy++;
	}
	return (res);
}
