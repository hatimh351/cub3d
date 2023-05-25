/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlahwaou <hlahwaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 09:14:12 by hlahwaou          #+#    #+#             */
/*   Updated: 2023/05/24 11:43:59 by hlahwaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// NO SO WE EA F C

int	check_rgb(char *str)
{
	int	cama;
	int	digits;
	int	i;

	cama = 2;
	digits = 3;
	i = 0;
	while (str[i])
	{
		if (str[i] == '+')
			if (!ft_isdigit(str[i++ + 1]))
				return (-1);
		digits = digits - ft_isdigit(str[i]);
		while (ft_isdigit(str[i]))
			i++;
		cama = cama - (str[i] == ',');
		if (str[i] != '\0' && str[i] != ',' && str[i] != '\0')
			return (0);
		i = i + (str[i] != '\0');
	}
	return (cama == 0 && digits == 0);
}

int	all_elements_in(t_data *ptr)
{
	int			i;
	static int	err = 0;

	i = 0;
	while (i < 6)
	{
		err = (ptr->elements[i++] == NULL);
		if (err)
			return (0);
	}
	if (check_rgb(ptr->elements[4]) == 0 || check_rgb(ptr->elements[5]) == 0)
		return (0);
	return (1);
}
