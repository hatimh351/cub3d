/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlahwaou <hlahwaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 23:37:12 by hlahwaou          #+#    #+#             */
/*   Updated: 2023/05/20 07:54:18 by hlahwaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "/Users/hlahwaou/Desktop/MLX42/include/MLX42/MLX42.h"
#include "stdio.h"
#include "math.h"
#include "unistd.h"
#define WIDTH 1400
#define HEIGHT 600

#define SQUARE_SIZE 30
typedef struct s_point
{
	double	x;
	double	y;
}	t_point;

typedef struct s_cub3d
{
	mlx_t		*mlx;
	mlx_image_t	*map_img;
	double		angle;
	double		xpos;
	double		ypos;
	int			map_height;
	int			map_width;
	int			right;
	int			down;
	char		**map;
}   t_cub3d;

// map drawing
void	draw_map(t_cub3d *ptr);
int		draw_cercel(t_cub3d *ptr, int x, int y);
void	draw_player(t_cub3d *ptr);
// hooks
void	key_hooks(void *param);
// utils
int 	get_color(int r, int g, int b, int a);
void	get_player_position(t_cub3d *ptr);
int		map_protection(t_cub3d *ptr, int x, int y);
int		there_is_wall(t_cub3d *ptr, double x, double y);

// intersection
int		horizontal_intersection(t_cub3d *ptr);
void	ft_facing(t_cub3d *ptr);