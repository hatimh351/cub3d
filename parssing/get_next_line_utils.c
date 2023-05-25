/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlahwaou <hlahwaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 23:10:42 by hlahwaou          #+#    #+#             */
/*   Updated: 2023/05/23 19:30:54 by hlahwaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	check_new_line(char *str)
{
	size_t	i;

	if (str == NULL)
		return (0);
	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strjoin_gl(char *s1, char *s2)
{
	size_t	i;
	char	*p;
	size_t	j;

	j = 0;
	if (!(s1))
		return (ft_strdup(s2));
	while ((s1)[j])
		j++;
	i = 0;
	while (s2[i])
		i++;
	j += i;
	p = malloc(j + 1);
	if (!p)
		return (free((s1)), NULL);
	j = 0;
	i = 0;
	while ((s1)[i])
		p[i++] = (s1)[j++];
	j = 0;
	while (s2[j])
		p[i++] = s2[j++];
	p[i] = '\0';
	return (free(s1), p);
}


char	*go_new_line(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (str + i + 1);
		i++;
	}
	return (NULL);
}
