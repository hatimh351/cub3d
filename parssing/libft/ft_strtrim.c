/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlahwaou <hlahwaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 17:12:54 by hlahwaou          #+#    #+#             */
/*   Updated: 2022/10/07 17:12:54 by hlahwaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	check_f_index(char *str, char *set)
{
	size_t	i;
	size_t	j;
	int		cond;

	i = 0;
	cond = 0;
	while (str[i])
	{
		j = 0;
		cond = 0;
		while (set[j])
		{
			if (set[j] == str[i])
				cond = 1;
			j++;
		}
		if (cond == 0)
			break ;
		i++;
	}
	return (i);
}

static size_t	check_l_index(char *str, char *set, size_t i, size_t n)
{
	size_t	j;
	int		cond;

	cond = 0;
	while (i >= 0 && i > n)
	{
		j = 0;
		cond = 0;
		while (set[j])
		{
			if (set[j] == str[i])
				cond = 1;
			j++;
		}
		if (cond == 0)
			break ;
		i--;
	}
	return (i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	f_index;
	size_t	l_index;
	size_t	len;
	char	*p;

	if (!set || !s1)
		return (0);
	if (set[0] == '\0')
		return (ft_strdup(s1));
	len = ft_strlen(s1);
	f_index = check_f_index((char *)s1, (char *)set);
	l_index = check_l_index((char *)s1, (char *)set, len - 1, f_index);
	p = ft_substr(s1, f_index, l_index - f_index + 1);
	return (p);
}
