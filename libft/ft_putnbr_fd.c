/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeisler <ekeisler@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 17:37:41 by ekeisler          #+#    #+#             */
/*   Updated: 2024/11/21 14:33:34 by ekeisler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

void	ft_putnbr_fd(int n, int fd)
{
	char	*rslt;
	size_t	ncpy;

	rslt = NULL;
	ncpy = n;
	if (n < 0)
	{
		ncpy *= -1;
		ft_putchar_fd('-', fd);
	}
	if (ncpy > 9)
	{
		ft_putnbr_fd(ncpy / 10, fd);
		ft_putnbr_fd(ncpy % 10, fd);
	}
	else
		ft_putchar_fd(ncpy + '0', fd);
}
