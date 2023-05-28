/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handel_color.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlahwaou <hlahwaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 10:38:29 by hlahwaou          #+#    #+#             */
/*   Updated: 2023/05/28 11:09:02 by hlahwaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// NO SO WE EA F C

static int	rgb_to_int(char *str)
{
	int	i;
	int	result;
	int	nbr;

	i = 1;
	result = 0;
	while (*str)
	{
		nbr = ft_atoi(str);
		if (nbr == -1)
			return (-1);
		result = nbr << (32 - 8 * i) | result;
		i++;
		while (*str && *str != ',')
			str++;
		if (*str)
			str++;
	}
	result = result | 255;
	return (result);
}

int	handel_rgb(t_data *ptr)
{
	ptr->ceil = rgb_to_int(ptr->elements[5]);
	ptr->floor = rgb_to_int(ptr->elements[4]);
	if (ptr->ceil == -1 || ptr->floor == -1)
		return (-1);
	return (0);
}
