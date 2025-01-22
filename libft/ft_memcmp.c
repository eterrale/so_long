/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeisler <ekeisler@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 16:15:24 by ekeisler          #+#    #+#             */
/*   Updated: 2024/11/21 14:33:34 by ekeisler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*s1_cpy;
	const unsigned char	*s2_cpy;
	size_t				i;

	s1_cpy = (const unsigned char *) s1;
	s2_cpy = (const unsigned char *) s2;
	i = 0;
	while (i < n)
	{
		if (s1_cpy[i] != s2_cpy[i])
		{
			return ((int)(s1_cpy[i] - s2_cpy[i]));
		}
		i++;
	}
	return (0);
}
