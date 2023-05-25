/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlahwaou <hlahwaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 23:10:39 by hlahwaou          #+#    #+#             */
/*   Updated: 2023/05/24 15:35:33 by hlahwaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_line(int fd, char *bufr, char **str, char *fail)
{
	size_t	i;

	i = 1;
	while (i > 0 && !check_new_line(*str))
	{
		i = read(fd, bufr, BUFFER_SIZE);
		bufr[i] = '\0';
		*str = ft_strjoin_gl(*str, bufr);
		if (!(*str))
			return (free(bufr), *fail = 1, NULL);
		if (*(str)[0] == '\0')
			return (free(bufr), free(*str), NULL);
	}
	return (free(bufr), *str);
}

char	*get_next_line(int fd, char *fail)
{
	char		*tp;
	static char	*str;
	char		*bufr;

	bufr = malloc(BUFFER_SIZE + 1);
	if (!bufr)
		return (*fail = 1, NULL);
	str = get_line(fd, bufr, &str, fail);
	if (!str)
		return (NULL);
	if (check_new_line(str) == 0)
	{
		tp = str;
		return (str = 0, tp);
	}
	tp = ft_strdup(go_new_line(str));
	if (!tp)
		return (free(str), *fail = 1, NULL);
	*go_new_line(str) = '\0';
	bufr = tp;
	tp = str;
	str = bufr;
	tp[ft_strlen(tp) - 1] = '\0';
	return (tp);
}
