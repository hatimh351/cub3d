/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlahwaou <hlahwaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 20:55:50 by hlahwaou          #+#    #+#             */
/*   Updated: 2022/10/24 17:15:12 by hlahwaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, void const *src, size_t	n)
{
	size_t		i;
	char		*dest_;
	char		*src_;

	if (!dst && !src)
		return (0);
	if (n == 0)
		return (dst);
	dest_ = (char *)dst;
	src_ = (char *)src;
	i = 0;
	while (i < n)
	{
		dest_[i] = src_[i];
		i++;
	}
	return (dst);
}
