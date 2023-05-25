/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlahwaou <hlahwaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 23:47:27 by hlahwaou          #+#    #+#             */
/*   Updated: 2023/05/21 11:13:25 by hlahwaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_square(t_cub3d *ptr, int x, int y, unsigned int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < SQUARE_SIZE)
	{
		j = 0;
		while (j < SQUARE_SIZE)
		{
			mlx_put_pixel(ptr->map_img, i + x, y + j, color);
			j++;
		}
		i++;
	}
}

void	draw_map(t_cub3d *ptr)
{
	int	x;
	int	y;

	y = 0;
	while (y < ptr->map_height)
	{
		x = 0;
		while (x < ptr->map_width)
		{
			if (ptr->map[y][x] == '1')
				draw_square(ptr, x * SQUARE_SIZE, y * SQUARE_SIZE, get_color(0,50,50,255));
			else
				draw_square(ptr, x * SQUARE_SIZE, y * SQUARE_SIZE, get_color(255, 255, 255, 255));
			x++;
		}
		y++;
	}
}

void	draw_player(t_cub3d *ptr)
{
	double	x;
	double	y;
	double	len;

	len = 1;
	ft_facing(ptr);
	horizontal_intersection(ptr);
	if (draw_cercel(ptr, ptr->xpos, ptr->ypos) == -1)
		return;
	while (len < 40)
	{
		x = round(cos(ptr->angle * (M_PI / 180)) * len);
		y = round(sin(ptr->angle * (M_PI / 180)) * len);
		if (map_protection(ptr, x + ptr->xpos, y + ptr->ypos))
			mlx_put_pixel(ptr->map_img, x + ptr->xpos, y + ptr->ypos, get_color(255, 0, 0, 255));
		else
			return;
		len++;
	}
}