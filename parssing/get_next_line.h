/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlahwaou <hlahwaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 23:10:45 by hlahwaou          #+#    #+#             */
/*   Updated: 2023/05/24 16:32:46 by hlahwaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>
#include "libft/libft.h"
#include "stdio.h"

#define BUFFER_SIZE 1
char	*ft_strjoin_gl(char *s1, char *s2);
int		check_new_line(char *str);
char	*get_next_line(int fd, char *fail);
char	*go_new_line(char *str);


#endif
