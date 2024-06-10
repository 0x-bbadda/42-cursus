/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbadda <bbadda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 08:06:15 by bbadda            #+#    #+#             */
/*   Updated: 2024/03/04 15:38:19 by bbadda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif 

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <limits.h>

char	*get_next_line(int fd);
size_t	__lenline(char *stow);
char	*__dupline(char *src);
char	*__linechr(char *str, int c);
char	*__joinline(char *s1, char *s2);
char	*__subline(char *str, unsigned int start, size_t len);
char	*__linesub(char *stow, unsigned int start, size_t len);

#endif