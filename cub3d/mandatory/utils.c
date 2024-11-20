/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbadda <bbadda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 17:54:38 by bbadda            #+#    #+#             */
/*   Updated: 2024/11/19 16:08:20 by bbadda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

size_t  my_strlen(const char *str)
{
	size_t	len;

	len = 0;
	while (str && str[len])
		len++;
	return (len);
}

int	cmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && (s1[i] != '\0' || s2[i] != '\0' ))
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}

void	check_file_type(const char *s)
{
	size_t	len;

	len = my_strlen(s);
	if (len < 5 || cmp(s + (len - 4), ".cub", len - 4) != 0)
		__error2(7);
}

void	__error(int index, int fd)
{
	if (index == 0)
	{
		write(1, ERR_ARGS, 46);
		exit(0);
	}
	if (index == 1)
	{
		write(1, ERR_EMPTY, 50);
		exit(0);
	}
	if (index == 2)
	{
		write(1, ERR_OPEN, 27);
		close(fd);
		exit(0);
	}
}

void	__error2(int index)
{
	if (index == 4)
	{
		write(1, ERR_MAP, 14);
		exit(0);
	}
	if (index == 5)
	{
		write(1, ERR_SPLIT, 29);
		exit(0);
	}
	if (index == 6)
	{
		write(1, ERR_MEM, 17);
		exit(0);
	}
	if (index == 7)
	{
		write(1, ERR_FILE, 21);
		exit(0);
	}
}
