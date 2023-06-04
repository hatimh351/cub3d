/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_scene.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlahwaou <hlahwaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 01:03:08 by hlahwaou          #+#    #+#             */
/*   Updated: 2023/06/04 07:28:03 by hlahwaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_texture(t_scene *scene)
{
	if (scene->texture.no)
		mlx_delete_texture(scene->texture.no);
	if (scene->texture.so)
		mlx_delete_texture(scene->texture.so);
	if (scene->texture.we)
		mlx_delete_texture(scene->texture.we);
	if (scene->texture.ea)
		mlx_delete_texture(scene->texture.ea);
}

int	load_textrure(t_data *ptr, t_scene *scene)
{
	scene->texture.no = mlx_load_png(ptr->elements[0]);
	if (!scene->texture.no)
		return (-1);
	scene->texture.so = mlx_load_png(ptr->elements[1]);
	if (!scene->texture.so)
		return (free_texture(scene), -1);
	scene->texture.we = mlx_load_png(ptr->elements[2]);
	if (!scene->texture.we)
		return (free_texture(scene), -1);
	scene->texture.ea = mlx_load_png(ptr->elements[3]);
	if (!scene->texture.ea)
		return (free_texture(scene), -1);
	return (0);
}

void	player_dir(t_data *ptr, t_scene *scene)
{
	if (ptr->c_player == 'N')
		scene->p_dir = 270;
	else if (ptr->c_player == 'S')
		scene->p_dir = 90;
	else if (ptr->c_player == 'E')
		scene->p_dir = 0;
	else if (ptr->c_player == 'W')
		scene->p_dir = 180;
}

t_scene	*fill_scene(t_data *ptr, int fd)
{
	t_scene	*scene;

	close(fd);
	scene = ft_calloc(sizeof(t_scene), 1);
	if (!scene)
		return (free_elements(ptr), NULL);
	scene->ceil = ptr->ceil;
	scene->floor = ptr->floor;
	scene->p_pos.x = ptr->xpos;
	scene->p_pos.y = ptr->ypos;
	scene->map.grid = ptr->map;
	scene->map.h = ptr->height;
	scene->map.w = ptr->width;
	if (load_textrure(ptr, scene) == -1)
		return (free(scene), free_elements(ptr), NULL);
	player_dir(ptr, scene);
	free_elements(ptr);
	return (scene);
}
