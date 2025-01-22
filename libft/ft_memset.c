/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeisler <ekeisler@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 12:03:55 by ekeisler          #+#    #+#             */
/*   Updated: 2024/11/21 14:52:55 by ekeisler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	char		*cpy_s;
	size_t		i;

	cpy_s = s;
	i = 0;
	while (i != n)
	{
		*cpy_s = c;
		cpy_s++;
		i++;
	}
	return (s);
}
