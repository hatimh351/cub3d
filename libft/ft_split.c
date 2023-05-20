/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlahwaou <hlahwaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 16:43:31 by hlahwaou          #+#    #+#             */
/*   Updated: 2022/10/24 09:06:00 by hlahwaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	word_count(char *str, char c)
{
	size_t	j;
	size_t	i;
	size_t	n;

	i = 0;
	n = 0;
	while (str[i])
	{
		j = 1;
		while (str[i] == c && str[i])
			i++;
		while (str[i] != c && str[i])
		{
			if (j == 1)
			{
				n++;
				j = 0;
			}
			i++;
		}
	}
	return (n);
}

static void	free_p(char **p)
{
	size_t	i;

	i = 0;
	while (p[i] != 0)
		free(p[i++]);
	free(p);
	p = 0;
}

static void	ft_alloc_string(char **p, char *str, char c)
{
	size_t	start;
	size_t	i;
	size_t	k;

	k = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] != c && str[i])
		{
			start = i;
			while (str[i] != c && str[i])
				i++;
			p[k] = ft_substr(str, start, i - start);
			if (!p[k])
			{
				free_p(p);
				return ;
			}
			k++;
		}
		if (str[i] == '\0')
			return ;
		i++;
	}
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	char	**p;

	if (!s)
		return (0);
	i = word_count((char *)s, c);
	p = malloc(sizeof(char *) * i + sizeof(char *));
	if (!p)
		return (0);
	p[i] = 0;
	ft_alloc_string(p, (char *)s, c);
	if (!p)
		return (0);
	return (p);
}
