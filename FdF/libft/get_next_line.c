/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbadda <bbadda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 16:24:54 by bbadda            #+#    #+#             */
/*   Updated: 2024/03/23 03:18:13 by bbadda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
		{
			free(buffer);
			buffer = NULL;
			return (free(stash), stash = NULL, NULL);
		}
		tmp = stash;
		stash = __joinline(tmp, buffer);
		free(tmp);
		tmp = NULL;
	}
	return (free(buffer), buffer = NULL, stash);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*stow;
	int			i;

	i = 0;
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) == -1)
		return (free(stash), stash = NULL, NULL);
	if (!stash)
		stash = __dupline("");
	stash = __read(fd, stash);
	if (!stash)
		return (free(stash), stash = NULL, NULL);
	while (stash[i] && stash[i] != '\n')
		i++;
	if (stash[i] == '\n')
		i++;
	stow = __linesub(stash, 0, i);
	if (!stow)
		return (free(stash), stash = NULL, NULL);
	stash = __subline(stash, i, __lenline(stash));
	return (stow);
}
