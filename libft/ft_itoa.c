/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeisler <ekeisler@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 14:07:07 by ekeisler          #+#    #+#             */
/*   Updated: 2024/11/21 14:33:34 by ekeisler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_lenitoa(int n)
{
	int		count;
	long	i;

	i = n;
	count = 0;
	if (n == 0)
		count = 1;
	if (n < 0)
	{
		i *= -1;
		count++;
	}
	while (i > 0)
	{
		i /= 10;
		count ++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	long	cpy;
	char	*rslt;
	int		i;

	rslt = ft_calloc(ft_lenitoa(n) + 1, sizeof(char));
	if (!rslt)
		return (NULL);
	cpy = n;
	i = ft_lenitoa(n) - 1;
	if (n < 0)
		cpy *= -1;
	while (cpy > 0)
	{
		rslt[i] = (cpy % 10) + '0';
		cpy /= 10;
		i--;
	}
	if (n < 0)
		rslt[i] = '-';
	if (n == 0)
		rslt[i] = '0';
	return (rslt);
}
