/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlahwaou <hlahwaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 23:54:50 by hlahwaou          #+#    #+#             */
/*   Updated: 2022/10/22 14:57:05 by hlahwaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long long	final_result(const char *str_, int signe)
{
	long long	nbr;
	long long	kifkif;
	int			i;

	i = 0;
	nbr = 0;
	while (str_[i] <= '9' && str_[i] >= '0')
	{
		kifkif = nbr;
		nbr = nbr * 10 + (str_[i] - 48);
		if (kifkif != nbr / 10 && signe == -1)
			return (0);
		else if (kifkif != nbr / 10 && signe == 1)
			return (-1);
		i++;
	}
	return (nbr * signe);
}

int	ft_atoi(const char *str)
{
	int			i;
	int			signe;

	i = 0;
	signe = 1;
	while ((str[i] <= 13 && str[i] >= 9) || str[i] == ' ')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			signe *= -1;
		i++;
	}
	return (final_result(str + i, signe));
}
