/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlahwaou <hlahwaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 01:00:53 by hlahwaou          #+#    #+#             */
/*   Updated: 2023/05/20 04:39:30 by hlahwaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int get_color(int r, int g, int b, int a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

int	draw_cercel(t_cub3d *ptr, int x, int y)
{
	double	i;
	double	j;

	x = x - 5;
	y = y - 5;
	i = 0;
	while (i <= 10)
	{
		j = 0;
		while (j <= 10)
		{
			if (sqrt((((j * 2) / 10) - 1) * (((j * 2) / 10) - 1) + (((i * 2) / 10) - 1) * (((i * 2) / 10) - 1)) < 0.45)
			{
				if (map_protection(ptr, j + x, y + i))
					mlx_put_pixel(ptr->map_img, j + x, y + i, get_color(255, 0, 0, 255));
				else
					return (-1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int map_protection(t_cub3d *ptr, int x, int y)
{
	if (x < 0 || y < 0)
		return (0);
	if (x > (ptr->map_width * 20) || y > (ptr->map_height * 20))
		return (0);
	return (1);
}

int	there_is_wall(t_cub3d *ptr, double x, double y)
{
	x = x / 20;
	y = y / 20;
	if (ptr->map[(int)floor(y)][(int)floor(x)] == '1')
		return (1);
	return (0);
}

void	get_player_position(t_cub3d *ptr)
{
	int	i;
	int	j;

	i = 0;
	while (i < ptr->map_height)
	{
		j = 0;
		printf("%s\n",ptr->map[i]);
		while (j < ptr->map_width)
		{
			if (ptr->map[i][j] == 'P')
			{
				ptr->xpos = 20 * j;
				ptr->ypos = 20 * i;
				return;
			}
			j++;
		}
		i++;
	}
}