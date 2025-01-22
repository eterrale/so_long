/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeisler <ekeisler@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 16:06:41 by ekeisler          #+#    #+#             */
/*   Updated: 2024/11/21 15:39:19 by ekeisler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_setnullchar(char *cpy)
{
	cpy = ft_calloc(1, sizeof(char));
	if (!cpy)
		return (NULL);
	return (cpy);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*cpy;
	size_t	i;
	size_t	substr_len;

	cpy = NULL;
	if (start >= ft_strlen(s))
		return (ft_setnullchar(cpy));
	substr_len = ft_strlen(s) - start;
	if (substr_len > len)
		substr_len = len;
	cpy = ft_calloc(substr_len + 1, sizeof(char));
	if (!cpy)
		return (NULL);
	i = 0;
	while (i < substr_len)
	{
		cpy[i] = s[start + i];
		i++;
	}
	return (cpy);
}
