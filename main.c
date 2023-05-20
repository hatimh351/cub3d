/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlahwaou <hlahwaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 23:36:54 by hlahwaou          #+#    #+#             */
/*   Updated: 2023/05/20 04:32:43 by hlahwaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*map[10] = {"1111111111",
					"1111001111",
					"1111001111",
					"11110P0011",
					"1111100011",
					"1111111111"};

void init(t_cub3d *ptr)
{
	ptr->mlx = mlx_init(WIDTH, HEIGHT, "cub3d", false);
	ptr->map = map;
	ptr->map_height = 6;
	ptr->map_width = 10;
	ptr->angle = 0;
	ptr->map_img = mlx_new_image(ptr->mlx, ptr->map_width * 20, ptr->map_height * 20);
	mlx_image_to_window(ptr->mlx, ptr->map_img, 0, 0);
	get_player_position(ptr);
	printf("%f %f\n",ptr->xpos, ptr->ypos);
}

int main()
{
	t_cub3d	cub3d;

	init(&cub3d);
	draw_map(&cub3d);
	draw_player(&cub3d);
	mlx_loop_hook(cub3d.mlx, key_hooks, &cub3d);
	mlx_loop(cub3d.mlx);
	mlx_terminate(cub3d.mlx);
}