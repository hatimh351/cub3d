/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlahwaou <hlahwaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 14:16:22 by hlahwaou          #+#    #+#             */
/*   Updated: 2022/10/22 17:13:47 by hlahwaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*p;
	size_t	n;

	if (!s)
		return (0);
	n = ft_strlen(s);
	if (len == 0 || start >= n)
		return (ft_strdup(""));
	i = 0;
	if (n < len)
		len = n;
	p = (char *)malloc(sizeof(char) * len + 1);
	if (!p)
		return (0);
	while (s[start] && i < len)
	{
		p[i] = s[start];
		i++;
		start++;
	}
	p[i] = '\0';
	return (p);
}
