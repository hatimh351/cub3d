/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handel_elements.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlahwaou <hlahwaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 08:20:07 by hlahwaou          #+#    #+#             */
/*   Updated: 2023/05/25 15:13:39 by hlahwaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// NO SO WE EA F C

void	free_splite(char **av)
{
	int	i;

	i = 0;
	while (av[i])
		free(av[i++]);
	free(av);	
}

int	is_element(char **elements,char **av)
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

int	check_elements(t_data *ptr, char **av, char **elements, int *n_elements)
{
	int	cond;
	int	i;

	i = 0;
	while (av[i])
		i++;	
	cond = is_element(elements, av);
	if (cond == NOTHING)
		return (0);
	if (cond == -1)
		return (-1);
	if (ptr->elements[cond] || i != 2)
		return (-1);
	(*n_elements) -= 1;
	ptr->elements[cond] = ft_strdup(av[1]);
	if (!ptr->elements[cond])
		return (-1);
	return (0);
}

int handel_elements(t_data *ptr, int fd)
{
	char		**elements;
	char		*p;
	char		**av;
	static char	fail = 0;
	static int	n_elements = 6;

	elements = ft_split("NO SO WE EA F C", ' ');
	if (!elements)
		return (-1);
	p = get_next_line(fd, &fail);
	if (fail)
		return (-1);
	while (p && n_elements)
	{
		av = ft_split(p, ' ');
		if (!av)
			return (free_splite(elements), free(p), -1);
		if (check_elements(ptr, av, elements, &n_elements) == -1)
			return (free_splite(elements), free_splite(av), free(p), -1);
		free_splite(av);
		free(p);
		if (!n_elements)
			break ;
		p = get_next_line(fd, &fail);
		if (fail)
			return (free_splite(elements), -1);
	}
	return (free_splite(elements), 0);
}

int	get_elements(int fd, t_data *ptr)
{
	if (handel_elements(ptr, fd) == -1)
		return (-1);
	if (!all_elements_in(ptr))
		return (-1);
	return (0);
}


int	main()
{
	t_data *ptr;
	t_lines *head;
	int		fd;

	ptr = ft_calloc(sizeof(t_data), 1);
	fd = open("file.cub", O_RDONLY);
	if (get_elements(fd, ptr) == -1)
		printf("NO\n");
	else
	{
		int	i;
		i = 0;
		while (i < 6)
			printf("%s\n", ptr->elements[i++]);
		height_width (fd, ptr, &head);
	}
	char	**map = creat_map(head, ptr->height, ptr->width);
	int i,j;

	i = 0;
	while (i < ptr->height)
	{
		j = 0;
		while (j < ptr->width)
		{
			printf("%c", map[i][j]);
			j++;
		}
		printf("'\n");
		i++;
	}
	t_lines *tmp;
	i = 0;
	while (map[i])
		free(map[i++]);
	free(map);	
	while (head)
	{
		tmp = head;
		head = head->next;
		free(tmp->line);
		free(tmp);
	}
	while (1);	
}