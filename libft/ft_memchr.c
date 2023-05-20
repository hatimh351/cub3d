/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlahwaou <hlahwaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 23:02:50 by hlahwaou          #+#    #+#             */
/*   Updated: 2022/10/20 11:02:36 by hlahwaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	c_;
	unsigned char	*s_;

	s_ = (unsigned char *)s;
	i = 0;
	c_ = (unsigned char)c;
	while (i < n)
	{
		if (s_[i] == c_)
			return ((void *)s + i);
		i++;
	}
	return (0);
}
