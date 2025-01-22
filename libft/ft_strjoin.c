/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeisler <ekeisler@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 17:14:51 by ekeisler          #+#    #+#             */
/*   Updated: 2024/11/21 15:06:39 by ekeisler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		size;
	char	*rslt;
	char	*rslt_start;

	size = ft_strlen(s1) + ft_strlen(s2);
	rslt = ft_calloc(size + 1, sizeof(char));
	if (rslt == NULL)
		return (NULL);
	rslt_start = rslt;
	while (*s1)
	{
		*rslt = *s1;
		rslt++;
		s1++;
	}
	while (*s2)
	{
		*rslt = *s2;
		rslt++;
		s2++;
	}
	return (rslt_start);
}
