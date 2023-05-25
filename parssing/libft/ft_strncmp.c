/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlahwaou <hlahwaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 22:45:07 by hlahwaou          #+#    #+#             */
/*   Updated: 2022/10/24 08:06:44 by hlahwaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*s1_;
	unsigned char	*s2_;

	s1_ = (unsigned char *)s1;
	s2_ = (unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (s1_[i] != s2_[i])
			return (s1_[i] - s2_[i]);
		if (s1_[i] == '\0' || s2_[i] == '\0')
			return (s1_[i] - s2_[i]);
		i++;
	}
	return (0);
}
