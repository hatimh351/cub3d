/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handel_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlahwaou <hlahwaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 16:26:41 by hlahwaou          #+#    #+#             */
/*   Updated: 2023/05/25 11:06:01 by hlahwaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	go_map(t_data *ptr, int fd, t_lines **tmp)
{
	char		*p;
	static char	fail = 0;

	p = get_next_line(fd, &fail);
	if (fail)
		return (-1);
	while (p)
	{
		if (ft_strlen(p) > 0)
		{
			ptr->width = ft_strlen(p);
			ptr->height++;
			*tmp = malloc(sizeof(t_lines));
			if (!(*tmp))
				return (free(p), -1);
			return ((*tmp)->line = p, (*tmp)->next = NULL, 0);
		}
		free(p);
		p = get_next_line(fd, &fail);
		if (fail)
			return (-1);
	}
	return (-1);
}

char	**creat_map(t_lines *head, int height, int width)
{
	char	**map;
	int		i;
	int		j;

	i = 0;
	map = malloc(sizeof(char *) * (height + 1));
	if (!map)
		return (NULL);
	while (i < height)
	{
		map[i] = malloc(width + 1);	
		if (!map[i])
			return (free_splite(map), NULL);
		j = -1;
		while (head->line[++j])
			map[i][j] = head->line[j];
		while (j < width)
			map[i][j++] = ' ';
		map[i][j] = '\0';
		j = 0;
		head = head->next;
		i++;
	}
	return (map);
}

int	max(int x, int y)
{
	if (x < y)
		x = y;
	return (x);
}

static int	node(t_lines *head, char *p)
{
	while (head->next)
		head = head->next;
	head->next = malloc(sizeof(t_lines));
	if (!head->next)
		return (-1);
	head = head->next;
	head->line = p;
	head->next = NULL;
	return (0);
}

int	height_width(int fd, t_data *ptr, t_lines **head)
{
	char		*p;
	static char	fail;
	t_lines		*tmp;

	if (go_map(ptr, fd, &tmp) == -1)
		return (-1);
	*head = tmp;
	p = get_next_line(fd, &fail);
	if (fail)
		return (-1);
	while (p)
	{
		 if (ft_strlen(p) == 0)
			break;
		ptr->width = max(ft_strlen(p), ptr->width);
		ptr->height++;
		if (node(*head, p) == -1)
			return (free(p), -1);
		p = get_next_line(fd, &fail);
		if (fail)
			return (-1);
	}
	return (free(p), 0);
}