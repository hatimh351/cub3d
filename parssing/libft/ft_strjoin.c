/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlahwaou <hlahwaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 14:30:12 by hlahwaou          #+#    #+#             */
/*   Updated: 2022/10/22 15:01:10 by hlahwaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	char	*p;
	int		j;

	if (s1 == 0 || s2 == 0)
		return (0);
	j = ft_strlen(s1);
	j += ft_strlen(s2);
	p = malloc(j + 1);
	if (!p)
		return (0);
	j = 0;
	i = 0;
	while (s1[i])
		p[i++] = s1[j++];
	j = 0;
	while (s2[j])
		p[i++] = s2[j++];
	p[i] = '\0';
	return (p);
}
