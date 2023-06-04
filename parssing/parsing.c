/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlahwaou <hlahwaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 10:18:47 by hlahwaou          #+#    #+#             */
/*   Updated: 2023/06/04 08:44:02 by hlahwaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	valid_name(char *file_name)
{
	int		len;
	int		i;
	char	*p;

	p = ".cub";
	i = 3;
	len = ft_strlen(file_name) - 1;
	while (len > 0 && i >= 0)
	{
		if (file_name[len] != p[i])
			return (0);
		i--;
		len--;
	}
	return (i == -1);
}

int	check_rows(t_data *ptr)
{
	char	c;
	int		i;
	int		j;
	int		out_side;

	i = -1;
	c = 0;
	while (++i < ptr->height)
	{
		out_side = 1;
		j = 0;
		while (j < ptr->width)
		{
			if (check_every_chars(ptr, i, j) == -1)
				return (-1);
			if (ptr->map[i][j] != ' ')
				c = ptr->map[i][j];
			if ((c != '1' && c != ' ') && out_side == 1)
				return (-1);
			out_side = (ptr->map[i][j++] == ' ');
		}
		if (c == '0')
			return (-1);
	}
	return (0);
}

int	check_columns(t_data *ptr)
{
	int			i;
	int			j;
	int			out_side;
	static char	c;

	j = -1;
	while (++j < ptr->width)
	{
		out_side = 1;
		i = 0;
		while (i < ptr->height)
		{
			if (check_every_chars(ptr, i, j) == -1)
				return (-1);
			if (ptr->map[i][j] != ' ')
				c = ptr->map[i][j];
			if ((c != '1' && c != ' ') && out_side == 1)
				return (-1);
			out_side = (ptr->map[i++][j] == ' ');
		}
		if (c == '0')
			return (-1);
	}
	return (0);
}

int	check_every_chars(t_data *ptr, int y, int x)
{
	if (ptr->map[y][x] == 'N' || ptr->map[y][x] == 'S' ||
		ptr->map[y][x] == 'W' || ptr->map[y][x] == 'E')
	{
		ptr->xpos = x;
		ptr->ypos = y;
		ptr->c_player = ptr->map[y][x];
		ptr->thre_is_player++;
	}
	else if (ptr->map[y][x] == '1' ||
		ptr->map[y][x] == '0' || ptr->map[y][x] == ' ')
		return (0);
	else
		return (-1);
	return (0);
}

t_scene	*pars_file(char *file_name)
{
	t_data	*ptr;
	int		fd;

	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		return (NULL);
	ptr = ft_calloc(sizeof(t_data), 1);
	if (!ptr)
		return (close(fd), NULL);
	if (!valid_name(file_name))
		return (close(fd), free(ptr), NULL);
	if (get_elements(fd, ptr) == -1)
		return (close(fd), free(ptr), NULL);
	if (get_map(ptr, fd) == -1)
		return (close(fd), free_all_elements(ptr), free(ptr), NULL);
	if (check_rows(ptr) == -1 || check_columns(ptr) == -1)
		return (close(fd), free_elements(ptr), NULL);
	if (ptr->thre_is_player != 2 || handel_rgb(ptr) == -1)
		return (close(fd), free_elements(ptr), NULL);
	return (fill_scene(ptr, fd));
}

int	main(int ac, char **av)
{

	t_scene *ptr = pars_file(av[1]);
	if (ptr)
	{
		printf("%d\n", ptr->ceil);
		printf("%d\n", ptr->floor);
	}
	while (1);	
}