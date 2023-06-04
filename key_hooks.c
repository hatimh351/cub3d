/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlahwaou <hlahwaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 01:15:54 by hlahwaou          #+#    #+#             */
/*   Updated: 2023/06/01 00:54:52 by hlahwaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	forward_backward(t_cub3d *ptr, int direction)
{
	if (map_protection(ptr,ptr->xpos + (cos(ptr->angle * (M_PI / 180))) * 1.5 *direction,ptr->ypos + (sin(ptr->angle * (M_PI / 180))) * 1.5 *direction))
	{
		if (there_is_wall(ptr,ptr->xpos + (cos(ptr->angle * (M_PI / 180))) * 1.5 *direction,ptr->ypos + (sin(ptr->angle * (M_PI / 180))) * 1.5 *direction))
			return;
		ptr->xpos += (cos(ptr->angle * (M_PI / 180))) * 2 * direction;
		ptr->ypos += (sin(ptr->angle * (M_PI / 180))) * 2 * direction;
		// printf("%f %f\n", (cos(ptr->angle * (M_PI / 180))), (sin(ptr->angle * (M_PI / 180))));
	}
}

static void	right_left(t_cub3d *ptr, int direction)
{
	if (map_protection(ptr,ptr->xpos + (sin(ptr->angle * (M_PI / 180))) * 1.5 * direction ,ptr->ypos + -(cos(ptr->angle * (M_PI / 180))) * 1.5 * direction))
	{
		if (there_is_wall(ptr,ptr->xpos + (sin(ptr->angle * (M_PI / 180))) * 1.5 * direction ,ptr->ypos + -(cos(ptr->angle * (M_PI / 180))) * 1.5 * direction))
			return;
		ptr->ypos += - ((cos(ptr->angle * (M_PI / 180))) * 2 * direction);
		ptr->xpos += ((sin(ptr->angle * (M_PI / 180))) * 2 * direction);
	}
}

static void	rotation(t_cub3d *ptr, int k)
{
	ptr->angle += (k * 3);
	if (ptr->angle >= 360)
		ptr->angle = 360 - ptr->angle;
	else if (ptr->angle < 0)
		ptr->angle = 360 + ptr->angle;	
}

void	key_hooks(void *param)
{
	t_cub3d *ptr;

	ptr = (t_cub3d *)param;
	if (mlx_is_key_down(ptr->mlx, MLX_KEY_UP))
		forward_backward(ptr, 1);
	else if (mlx_is_key_down(ptr->mlx, MLX_KEY_DOWN))
		forward_backward(ptr, -1);
	if (mlx_is_key_down(ptr->mlx, MLX_KEY_D))
		right_left(ptr, 1);
	else if (mlx_is_key_down(ptr->mlx, MLX_KEY_A))
		right_left(ptr, -1);
	if (mlx_is_key_down(ptr->mlx, MLX_KEY_LEFT))
		rotation(ptr, -1);
	else if (mlx_is_key_down(ptr->mlx, MLX_KEY_RIGHT))
		rotation(ptr, 1);
	draw_map(ptr);
	draw_player(ptr);
}