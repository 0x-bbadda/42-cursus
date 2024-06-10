/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbadda <bbadda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 08:06:49 by bbadda            #+#    #+#             */
/*   Updated: 2024/03/04 15:38:00 by bbadda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*__linechr(char *str, int c)
{
	int		i;
	char	*p;

	i = 0;
	if (!str)
		return (NULL);
	p = (char *)str;
	while (p[i] != '\0')
	{
		if (p[i] == (char)c)
			return (p + i);
		i++;
	}
	if (p[i] == (char)c)
		return (p + i);
	return (0);
}

static char	*__read(int fd, char *stash)
{
	char	*buffer;
	char	*tmp;
	int		count;

	count = 1;
	buffer = (char *)malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	while (!__linechr(stash, '\n') && count > 0)
	{
		count = read(fd, buffer, BUFFER_SIZE);
		buffer[count] = '\0';
		if (count == 0 && !stash[0])
			return (free (buffer), free (stash), NULL);
		tmp = stash;
		stash = __joinline(tmp, buffer);
		free(tmp);
		tmp = NULL;
	}
	return (free(buffer), buffer = NULL, stash);
}

char	*get_next_line(int fd)
{
	static char	*stash[OPEN_MAX];
	char		*stow;
	int			i;

	i = 0;
	if (fd < 0 || fd > OPEN_MAX || BUFFER_SIZE <= 0 || read(fd, 0, 0) == -1)
	{
		if (fd < 0)
			return (NULL);
		return (free(stash[fd]), stash[fd] = NULL, NULL);
	}
	if (!stash[fd])
		stash[fd] = __dupline("");
	stash[fd] = __read(fd, stash[fd]);
	if (!stash[fd])
		return (NULL);
	while (stash[fd][i] && stash[fd][i] != '\n')
		i++;
	if (stash[fd][i] == '\n')
		i++;
	stow = __linesub(stash[fd], 0, i);
	if (!stow)
		return (free(stash[fd]), stash[fd] = NULL, NULL);
	stash[fd] = __subline(stash[fd], i, __lenline(stash[fd]));
	return (stow);
}
