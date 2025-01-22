/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeisler <ekeisler@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 15:39:04 by ekeisler          #+#    #+#             */
/*   Updated: 2024/11/21 15:22:07 by ekeisler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	s1_asc;
	size_t	s2_asc;
	size_t	c;

	s1_asc = 0;
	s2_asc = 0;
	c = 0;
	while (c != n && (s1[c] || s2[c]))
	{
		s1_asc = s1[c];
		s2_asc = s2[c];
		if ((s1_asc != s2_asc))
		{
			if (s1_asc < s2_asc)
				return (-1);
			if (s1_asc > s2_asc)
				return (1);
		}
		c++;
	}
	return (0);
}
