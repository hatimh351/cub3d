/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlahwaou <hlahwaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 18:51:36 by hlahwaou          #+#    #+#             */
/*   Updated: 2023/06/04 06:34:23 by hlahwaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "get_next_line.h"
#include "libft/libft.h"
#include "stdio.h"
#include "fcntl.h"
#include "unistd.h"
#include "/Users/hlahwaou/Desktop/MLX42/include/MLX42/MLX42.h"


// typedef struct s_scene
// {
//     char        **map;
//     int            map_w;
//     int            map_h;
//     t_color        floor;
//     t_color        ceiling;
//     t_texture    texture;
// }    t_scene;
// typedef uint32_t            t_color;

// typedef struct s_texture
// {
//     char    *no;
//     char    *so;
//     char    *we;
//     char    *ea;
// }    t_texture;

typedef struct s_map
{
    int        w;
    int        h;
    char    **grid;
}    t_map;

typedef struct s_texture
{
    mlx_texture_t    *no;
    mlx_texture_t    *so;
    mlx_texture_t    *we;
    mlx_texture_t    *ea;
}    t_texture;

typedef struct s_pos
{
	int	x;	
	int	y;	
} t_pos;
typedef uint32_t            t_color;

typedef struct s_scene
{
    t_map            map;
    float            p_dir;
    t_pos            p_pos;
    t_color            ceil;
    t_color            floor;
    t_texture        texture;
}    t_scene;

typedef struct s_lines
{
	char	*line;
	struct s_lines *next;
}	t_lines;

typedef struct s_data
{
	char	*elements[7];
	int		height;
	int		width;
	int		angle;
	t_lines	*head;
	char	**map;
	int		thre_is_player;
	int		ceil;
	int		floor;
	int		xpos;
	int		ypos;
	char	c_player;
}	t_data;


int 	all_elements_in(t_data *ptr);
int 	check_rgb(char *str);
int		height_width(int fd, t_data *ptr, t_lines **head);
void	free_splite(char **av);
char	**creat_map(t_lines *head, int height, int width);
void	free_lines(t_lines *head);
int		max(int x, int y);
int		node(t_lines *head, char *p);
int		check_every_chars(t_data *ptr, int y, int x);

int		handel_rgb(t_data *ptr);


int		get_map(t_data *ptr, int fd);
int		get_elements(int fd, t_data *ptr);

void	free_elements(t_data *ptr);
t_scene	*fill_scene(t_data *ptr, int fd);
void	free_all_elements(t_data *ptr);
#define NOTHING 10