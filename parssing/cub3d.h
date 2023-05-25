/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlahwaou <hlahwaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 18:51:36 by hlahwaou          #+#    #+#             */
/*   Updated: 2023/05/25 09:39:38 by hlahwaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "get_next_line.h"
#include "libft/libft.h"
#include "stdio.h"
#include "fcntl.h"
#include "unistd.h"

typedef struct s_data
{
	char	*elements[6];
	int		height;
	int		width;
	int		angle;
}	t_data;

typedef struct s_lines
{
	char	*line;
	struct s_lines *next;
}	t_lines;

int 	all_elements_in(t_data *ptr);
int 	check_rgb(char *str);
int		height_width(int fd, t_data *ptr, t_lines **head);
void	free_splite(char **av);
char	**creat_map(t_lines *head, int height, int width);
#define NOTHING 10