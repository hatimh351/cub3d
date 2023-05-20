/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlahwaou <hlahwaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 22:14:02 by hlahwaou          #+#    #+#             */
/*   Updated: 2022/10/23 10:31:50 by hlahwaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	c_;

	i = 0;
	c_ = (char)c;
	while (s[i])
	{
		if (c_ == s[i])
			return ((char *)s + i);
		i++;
	}
	if (c_ == '\0' && s[i] == '\0')
		return ((char *)s + i);
	return (0);
}
