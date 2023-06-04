/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handel_elements.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlahwaou <hlahwaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 08:20:07 by hlahwaou          #+#    #+#             */
/*   Updated: 2023/06/04 08:45:28 by hlahwaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_element(char **elements, char **av)
{
	int	i;

	i = 0;
	if (av[0] == NULL)
		return (NOTHING);
	while (elements[i])
	{
		if (ft_strcmp(elements[i], av[0]) == 0)
			return (i);
		i++;
	}
	return (-1);
}

int	check_elements(t_data *ptr, char *p, char **elements, int *n_elements)
{
	int		cond;
	int		i;
	char	**av;

	i = 0;
	av = ft_split(p, ' ');
	if (!av)
		return (-1);
	while (av[i])
		i++;
	cond = is_element(elements, av);
	if (cond == NOTHING)
		return (free_splite(av), 0);
	if (cond == -1)
		return (free_splite(av), -1);
	if (ptr->elements[cond] || i != 2)
		return (free_splite(av), -1);
	(*n_elements) -= 1;
	ptr->elements[cond] = ft_strdup(av[1]);
	if (!ptr->elements[cond])
		return (free_splite(av), -1);
	return (free_splite(av), 0);
}

int	handel_elements(t_data *ptr, int fd)
{
	char		**elements;
	char		*p;
	static char	fail = 0;
	static int	n_elements = 6;

	elements = ft_split("NO SO WE EA F C", ' ');
	if (!elements)
		return (-1);
	p = get_next_line(fd, &fail);
	if (fail)
		return (free_splite(elements), -1);
	while (p && n_elements)
	{
		if (check_elements(ptr, p, elements, &n_elements) == -1)
			return (free_splite(elements), free(p), -1);
		if (!n_elements)
			break ;
		free(p);
		p = get_next_line(fd, &fail);
		if (fail)
			return (free_splite(elements), -1);
	}
	free(p);
	return (free_splite(elements), 0);
}

int	get_elements(int fd, t_data *ptr)
{
	int	i;

	i = 0;
	if (handel_elements(ptr, fd) == -1)
		return (-1);
	if (!all_elements_in(ptr))
		return (free_all_elements(ptr), -1);
	return (0);
}

int	get_map(t_data *ptr, int fd)
{
	char		*p;
	static char	fail = 0;

	if (height_width(fd, ptr, &ptr->head) == -1)
		return (free_lines(ptr->head), -1);
	ptr->map = creat_map(ptr->head, ptr->height, ptr->width);
	free_lines(ptr->head);
	if (!ptr->map)
		return (-1);
	p = get_next_line(fd, &fail);
	if (fail)
		return (free_splite(ptr->map), -1);
	while (p)
	{
		if (ft_strlen(p) > 0)
			return (free(p), free_splite(ptr->map), -1);
		free(p);
		p = get_next_line(fd, &fail);
		if (fail)
			return (free_splite(ptr->map), free_splite(ptr->map), -1);
	}
	return (0);
}
