/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlahwaou <hlahwaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 10:18:47 by hlahwaou          #+#    #+#             */
/*   Updated: 2023/05/28 11:08:59 by hlahwaou         ###   ########.fr       */
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
			if (check_every_chars(ptr, ptr->map[i][j]) == -1)
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
			if (check_every_chars(ptr, ptr->map[i][j]) == -1)
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

int	check_every_chars(t_data *ptr, char c)
{
	if (c == 'N' || c == 'S' || c == 'W' || c == 'E')
		ptr->thre_is_player++;
	else if (c == '1' || c == '0' || c == ' ')
		return (0);
	else
		return (-1);
	return (0);
}

int	pars_file(t_data *ptr, int fd, char *file_name)
{
	if (!valid_name(file_name) || get_elements(fd, ptr) == -1)
		return (-1);
	if (get_map(ptr, fd) == -1)
		return (free_splite(ptr->elements), -1);
	if (check_rows(ptr) == -1 || check_columns(ptr) == -1)
		return (free_splite(ptr->elements), free_splite(ptr->map), -1);
	if (ptr->thre_is_player != 2 || handel_rgb(ptr) == -1)
		return (-1);
	return (0);
}

int	main(int ac, char **av)
{
	t_data *ptr;
	int		fd;

	ptr = ft_calloc(sizeof(t_data), 1);
	fd = open("file.cub", O_RDONLY);
	if (pars_file(ptr, fd, av[1]) == 0)
	{int	i;
	i = 0;
	while (ptr->map[i])
	{
		printf("%s\n", ptr->map[i]);
		i++;
	}
	}
	while (1);	
}