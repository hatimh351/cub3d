/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlahwaou <hlahwaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 22:37:06 by hlahwaou          #+#    #+#             */
/*   Updated: 2022/10/23 10:31:22 by hlahwaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;
	char	p;

	p = (char)c;
	i = ft_strlen(s);
	while (i > 0)
	{
		if (s[i] == p)
			return ((char *)s + i);
		i--;
	}
	if (s[i] == p)
		return ((char *)s + i);
	return (0);
}
