/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbadda <bbadda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 14:47:12 by bbadda            #+#    #+#             */
/*   Updated: 2024/06/09 13:26:34 by bbadda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int	start_lenth(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != ',')
		i++;
	return (++i);
}

float	__abs(float p2, float p1)
{
	float	r;

	r = p2 - p1;
	if (r < 0)
		r *= -1;
	return (r);
}

int	__num(char c)
{
	int	r;

	r = 0;
	if (ft_isalnum(c))
	{
		if (ft_isdigit(c))
			r = c - 48;
		else
		{
			if (c >= 97 && c <= 122)
				r = c - 97 + 10;
			if (c >= 65 && c <= 90)
				r = c - 65 + 10;
		}
	}
	return (r);
}

int	hex_to_int(char *str)
{
	int		i;
	int		j;
	long	r;

	r = 0;
	j = 0;
	i = ft_strlen(str) - 1;
	if (i < 1)
		return (16777215);
	while (i >= 2)
	{
		r += __num(str[i]) * pow(16, j);
		i--;
		j++;
	}
	return (r);
}

void	__scale(t_map *map, int s)
{
	if (s <= 300)
		map->zoom = 25;
	else if (s <= 500)
		map->zoom = 20;
	else if (s <= 1000)
		map->zoom = 16;
	else if (s <= 5000)
		map->zoom = 10;
	else if (s <= 10100)
		map->zoom = 5;
	else if (s <= 200000)
		map->zoom = 3;
	else
		map->zoom = 1;
}
