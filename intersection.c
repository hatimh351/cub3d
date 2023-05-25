/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlahwaou <hlahwaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 05:13:20 by hlahwaou          #+#    #+#             */
/*   Updated: 2023/05/21 03:25:15 by hlahwaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_facing(t_cub3d *ptr)
{
	ptr->right = 0;
	ptr->down = 0;
	if (ptr->angle > 270 || ptr->angle < 90)
		ptr->right = 1;
	if (ptr->angle > 0 && ptr->angle < 180)
		ptr->down = 1;
}

static int	get_a_h(t_cub3d *ptr, t_point *a)
{
	a->y = (((int)ptr->ypos) / SQUARE_SIZE) * SQUARE_SIZE;
	if (ptr->down)
		a->y += SQUARE_SIZE;
	if (ptr->angle == 90 || ptr->angle == 270)
		return (a->x = ptr->xpos, 0);
	else if (ptr->angle == 180 || ptr->angle == 0)
		return (-1);
	else
		a->x = fabs((a->y - ptr->ypos) / tan(ptr->angle * (M_PI / 180)));
	if (!ptr->right)
		a->x *= -1;
	a->x += ptr->xpos;
	return (0); 
}

int	horizontal_intersection(t_cub3d *ptr)
{
	t_point	a;
	t_point	steps;
	int		c;
	int	i = 0;

	c = 0;
	if (!ptr->down)
		c = -1;
	if (get_a_h(ptr, &a) == -1)
		return (-1);
	if (!map_protection(ptr, a.x, a.y))
		return (-1);
	steps.y = SQUARE_SIZE;
	if (!ptr->down)
		steps.y *= -1;
	steps.x = fabs((steps.y) / tan(ptr->angle * (M_PI / 180)));
	if (!ptr->right)
		steps.x *= -1;
	while (!there_is_wall(ptr, a.x + steps.x * i, a.y + steps.y * i + c))
	{
		i++;
		if (!map_protection(ptr, a.x + steps.x * i, a.y + steps.y * i))
			return (-1);
	}
	a.x = a.x + steps.x * (i);
	a.y = a.y + steps.y * (i);
	int	j;
	int	k;
	j = 0 ;
	while (j < 4)
	{
		k = 0;
		while (k < 4)
		{
			if (!map_protection(ptr, a.x + j, a.y + k))
				return (-1);
			mlx_put_pixel(ptr->map_img, a.x + j, a.y + k, get_color(255, 0, 0, 200));
			k++;
		}
		j++;
	}
	return (0);
}

// static int	get_a_v(t_cub3d *ptr, t_point *a)
// {
// 	a->x = (((int)ptr->xpos) / SQUARE_SIZE) * SQUARE_SIZE;
// 	if (ptr->right)
// 		a->x += SQUARE_SIZE;

// 	if (ptr->angle == 90 || ptr->angle == 180)
// 		return (-1); 
// 	a->y = fabs((ptr->xpos - a->x) * tan(ptr->angle * (M_PI / 180)));
// 	if (!ptr->down)
// 		a->y *= -1;
// 	return (0);
// }

// int	verticale_intersection(t_cub3d *ptr)
// {
// 	t_point a;
// 	t_point steps;

// 	if (get_a_v(ptr, &a) == -1)
// 		return (-1);
// 	steps.x = SQUARE_SIZE;
// 	if (!ptr->right)
// 		steps.x *= -1;
	
// }