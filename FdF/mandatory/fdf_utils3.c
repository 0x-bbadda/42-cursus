/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbadda <bbadda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 17:49:58 by bbadda            #+#    #+#             */
/*   Updated: 2024/06/08 17:31:17 by bbadda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int	__max(t_map *map)
{
	int	i;
	int	j; 
	int	max;

	j = -1;
	max = map->p[0][0].z;
	while (++j < map->height)
	{
		i = -1;
		while (++i < map->width)
		{
			if (map->p[j][i].z > max)
				max = map->p[j][i].z;
		}
	}
	return (max);
}

int	__min(t_map *map)
{
	int	i;
	int	j;
	int	min;

	j = -1;
	i = 0;
	min = map->p[0][0].z;
	while (++j < map->height)
	{
		i = -1;
		while (++i < map->width)
		{
			if (map->p[j][i].z < min)
				min = map->p[j][i].z;
		}
	}
	return (min);
}

void	__free(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
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
	if (index == 3)
	{
		write(1, ERR_LINE, 54);
		exit(0);
	}
}
