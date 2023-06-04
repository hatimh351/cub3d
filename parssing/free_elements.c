/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_elements.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlahwaou <hlahwaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 06:00:58 by hlahwaou          #+#    #+#             */
/*   Updated: 2023/06/04 08:42:50 by hlahwaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_all_elements(t_data *ptr)
{
	int	i;

	i = 0;
	while (i < 6)
		free(ptr->elements[i++]);
}

void	free_elements(t_data *ptr)
{
	free_all_elements(ptr);
	free_splite(ptr->map);
	free(ptr);
}
