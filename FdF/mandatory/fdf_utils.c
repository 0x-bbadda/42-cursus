/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbadda <bbadda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 17:39:54 by bbadda            #+#    #+#             */
/*   Updated: 2024/06/09 13:28:10 by bbadda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	get_points_scales(t_map *map)
{
	t_int	index;
	int		a;

	index.sr = map->width * map->height;
	a = __abs(__max(map), __min(map));
	__scale(map, index.sr);
	index.j = -1;
	while (++index.j < map->height)
	{
		index.i = -1;
		while (++index.i < map->width)
		{
			map->p[index.j][index.i].x *= map->zoom;
			map->p[index.j][index.i].y *= map->zoom;
			if (a <= 30)
				map->p[index.j][index.i].z *= map->zoom;
			else
				map->p[index.j][index.i].z += map->zoom;
		}
	}
}

void	get_points(t_map *map, char **str, int fd)
{
	t_int	index;
	t_int	in;

	index.sr = map->width * map->height;
	index.j = -1;
	while (++index.j < map->height)
	{
		index.i = -1;
		while (++index.i < map->width)
		{
			map->p[index.j][index.i].x = index.i;
			map->p[index.j][index.i].y = index.j;
			map->p[index.j][index.i].z = ft_atoi(str[index.i]);
			in.j = start_lenth(str[index.i]);
			in.s = ft_substr(str[index.i], in.j, ft_strlen(str[index.i]));
			map->p[index.j][index.i].color = hex_to_int(in.s);
			free(in.s);
		}
		__free(str);
		in.s = get_next_line(fd);
		str = ft_split(in.s, ' ');
		free(in.s);
	}
	close(fd);
	get_points_scales(map);
}

void	allocate_for_me(t_map *map, t_int *init)
{
	t_int	info;

	info.i = 0;
	info.lenth = 0;
	map->p = malloc(sizeof(t_point *) * map->height);
	if (!map->p)
		__error2(6);
	info.s = get_next_line(init->fd2);
	init->str = ft_split(info.s, ' ');
	if (!init->str)
	{
		free(map->p);
		__error2(5);
	}
	free(info.s);
	map->width = -1;
	while (init->str[++map->width])
		;
	while (++init->j < map->height)
	{
		map->p[init->j] = malloc(sizeof(t_point) * map->width);
		if (!map->p)
			__error2(6);
	}
}

void	help_to_read(t_map *map, t_int *init)
{
	init->s = get_next_line(init->fd1);
	while (init->s)
	{
		free(init->s);
		init->s = get_next_line(init->fd1);
		init->i++;
	}
	if (init->i < 1)
		__error(1, 0);
	map->height = init->i;
	close(init->fd1);
}

void	read_from_file(char *av, t_map *map)
{
	t_int	init;

	init.s = NULL;
	init.str = NULL;
	init.i = 0;
	init.j = -1;
	init.fd1 = open(av, O_RDWR);
	if (init.fd1 == -1)
		__error(2, init.fd1);
	help_to_read(map, &init);
	init.fd2 = open(av, O_RDWR);
	if (init.fd2 == -1)
		__error(2, init.fd2);
	allocate_for_me(map, &init);
	get_points(map, init.str, init.fd2);
}
