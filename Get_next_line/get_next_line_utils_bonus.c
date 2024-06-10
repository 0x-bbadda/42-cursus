/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbadda <bbadda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 08:06:32 by bbadda            #+#    #+#             */
/*   Updated: 2024/03/04 15:37:52 by bbadda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	__lenline(char *stow)
{
	size_t	len;

	len = 0;
	if (!stow)
		return (0);
	while (stow[len])
		len++;
	return (len);
}

char	*__dupline(char *stow)
{
	char	*dst;
	int		i;
	int		len; 

	i = 0;
	len = __lenline(stow);
	dst = (char *)malloc(len + 1);
	if (!dst)
		return (NULL);
	while (i < len)
	{
		dst[i] = stow[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

char	*__joinline(char *stow, char *buffer)
{
	int		i;
	int		j;
	char	*result;
	int		len;

	i = 0;
	j = 0;
	if (!stow)
		return (__dupline(buffer));
	if (stow == NULL || buffer == NULL)
		return (NULL);
	len = __lenline(stow) + __lenline(buffer);
	result = (char *)malloc(len + 1);
	if (result == NULL)
		return (NULL);
	while (stow[i])
	{
		result[i] = stow[i];
		i++;
	}
	while (buffer[j])
		result[i++] = buffer[j++];
	result[len] = '\0';
	return (result);
}

char	*__subline(char *stow, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;

	if (!stow)
		return (NULL);
	if (start > __lenline(stow))
		return (__dupline(""));
	if (len > __lenline(stow) - start)
		len = __lenline(stow) - start;
	sub = (char *)malloc(len + 1);
	if (sub == NULL)
	{
		free(stow);
		stow = NULL;
		return (NULL);
	}
	i = 0;
	while (i < len)
	{
		sub[i] = stow[start];
		i++;
		start ++;
	}
	sub[i] = '\0';
	return (free(stow), stow = NULL, sub);
}

char	*__linesub(char *stow, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;

	if (!stow)
		return (NULL);
	if (start > __lenline(stow))
		return (__dupline(""));
	if (len > __lenline(stow) - start)
		len = __lenline(stow) - start;
	sub = (char *)malloc(len + 1);
	if (sub == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		sub[i] = stow[start];
		i++;
		start ++;
	}
	sub[i] = '\0';
	return (sub);
}
