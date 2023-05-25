/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlahwaou <hlahwaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 03:08:54 by hlahwaou          #+#    #+#             */
/*   Updated: 2022/10/24 17:26:00 by hlahwaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	nbr;

	nbr = n;
	if (nbr < 0)
	{
		ft_putchar_fd('-', fd);
		nbr *= -1;
	}
	if (nbr <= 9 && 0 <= nbr)
	{
		ft_putchar_fd(nbr + 48, fd);
	}
	else
	{
		ft_putnbr_fd((int)(nbr / 10), fd);
		ft_putnbr_fd((int)(nbr % 10), fd);
	}
}
