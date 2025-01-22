/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeisler <ekeisler@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 16:56:52 by ekeisler          #+#    #+#             */
/*   Updated: 2024/11/21 14:33:34 by ekeisler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char	*nptr)
{
	int	i;
	int	count;
	int	res;
	int	sign;

	i = 0;
	count = 0;
	sign = 1;
	res = 0;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == ' ')
		i++;
	while (nptr[i] == '+' || nptr[i] == '-')
	{
		count++;
		if (nptr[i] == '-' && count < 2)
			sign *= -1;
		i++;
	}
	while (ft_isdigit(nptr[i]) && count < 2)
	{
		res = res * 10 + (nptr[i] - '0');
		i++;
	}
	return (res * sign);
}
