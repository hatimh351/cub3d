/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlahwaou <hlahwaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 00:14:52 by hlahwaou          #+#    #+#             */
/*   Updated: 2022/10/24 08:05:22 by hlahwaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t			n;
	char			*p;
	unsigned int	i;
	char			*str;	

	if (!s)
		return (0);
	n = ft_strlen((s));
	i = 0;
	p = ft_calloc(1, n + 1);
	str = (char *)s;
	if (p == 0)
		return (0);
	while (i < n)
	{
		p[i] = (*f)(i, str[i]);
		i++;
	}
	return (p);
}
