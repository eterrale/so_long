/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeisler <ekeisler@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 15:43:29 by ekeisler          #+#    #+#             */
/*   Updated: 2024/11/21 14:33:34 by ekeisler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*rslt;
	size_t	size;
	size_t	i;

	size = ft_strlen(s);
	rslt = ft_calloc(size + 1, sizeof(char));
	if (!rslt)
		return (NULL);
	i = 0;
	while (i < size)
	{
		rslt[i] = f(i, s[i]);
		i++;
	}
	return (rslt);
}
