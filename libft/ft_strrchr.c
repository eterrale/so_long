/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeisler <ekeisler@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 14:52:13 by ekeisler          #+#    #+#             */
/*   Updated: 2024/11/21 15:29:22 by ekeisler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*res;
	int		n;

	n = ft_strlen(s);
	res = (char *) s;
	while (n >= 0)
	{
		if (s[n] == (char)c)
		{
			return (res + n);
		}
		n--;
	}
	return (NULL);
}
