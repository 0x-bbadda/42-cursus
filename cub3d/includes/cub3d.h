/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbadda <bbadda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 17:45:25 by bbadda            #+#    #+#             */
/*   Updated: 2024/11/19 16:08:20 by bbadda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "mlx.h"
# include "errors.h"
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include <fcntl.h>
# include <math.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

size_t		my_strlen(const char *str);
int			cmp(const char *s1, const char *s2, size_t n);
void		check_file_type(const char *s);
void		__error(int index, int fd);
void		__error2(int index);
//--------------------------get_next_line-----------------------------------//
char		*get_next_line(int fd);
char		*__linechr(char *str, int c);
size_t		__lenline(char *stow);
char		*__dupline(char *stow);
char		*__joinline(char *stow, char *buffer);
char		*__subline(char *stow, unsigned int start, size_t len);
char		*__linesub(char *stow, unsigned int start, size_t len);


#endif