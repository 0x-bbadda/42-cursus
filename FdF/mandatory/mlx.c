/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbadda <bbadda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 22:37:46 by bbadda            #+#    #+#             */
/*   Updated: 2024/06/09 18:50:35 by bbadda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	my_mlx_pixel_put(t_map *data, int x, int y, int color)
{
	char	*dst;

	if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
	{
		dst = data->img.addr + (y * data->img.size_line)
			+ x * (data->img.bpp / 8);
		*(unsigned int *)dst = color;
	}
}

void	isometric(t_point *p, t_map *map, float z)
{
	float	x;
	float	y;

	x = p->x;
	y = p->y;
	p->x = ((x - y) * cos(0.523599));
	p->y = (-z) + (x + y) * sin(0.523599);
	p->x += map->x_offset;
	p->y += map->y_offset;
}

int	do_gradiant(int color_p1, int color_p2, float pos)
{
	t_color	c_p1;
	t_color	c_p2;
	t_color	new_c;
	int		new_color;

	c_p1.r = (color_p1 >> 16) & 0xff;
	c_p1.g = (color_p1 >> 8) & 0xff;
	c_p1.b = (color_p1) & 0xff;
	c_p2.r = (color_p2 >> 16) & 0xff;
	c_p2.g = (color_p2 >> 8) & 0xff;
	c_p2.b = (color_p2) & 0xff;
	new_c.r = (c_p2.r - c_p1.r) * pos + c_p1.r;
	new_c.g = (c_p2.g - c_p1.g) * pos + c_p1.g;
	new_c.b = (c_p2.b - c_p1.b) * pos + c_p1.b;
	new_color = (new_c.r << 16) | (new_c.g << 8) | (new_c.b);
	return (new_color);
}

void	__bresnham(t_map *map, t_point p1, t_point p2)
{
	t_point	info;

	info.i = -1;
	isometric(&p1, map, p1.z);
	isometric(&p2, map, p2.z);
	info.x = p1.x;
	info.y = p1.y;
	abs_sign(&info, &p1, &p2);
	if (info.d.dy > info.d.dx)
		__bresnham2(map, p1, p2);
	info.p = (2 * info.d.dy) - info.d.dx;
	while (++info.i <= info.d.dx)
	{
		info.color = do_gradiant(p1.color, p2.color, (float)info.i / info.d.dx);
		my_mlx_pixel_put(map, (int)info.x, (int)info.y, info.color);
		if (p1.x == p2.x && p1.y == p2.y)
			break ;
		while (info.p >= 0)
		{
			info.p -= 2 * info.d.dx;
			info.y += info.sy;
		}
		info.p += 2 * info.d.dy;
		info.x += info.sx;
	}
}

int	__draw_map(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	clear_window(map);
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			if (j < map->width - 1)
				__bresnham(map, map->p[i][j], map->p[i][j + 1]);
			if (i < map->height - 1)
				__bresnham(map, map->p[i][j], map->p[i + 1][j]);
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(map->mlx_ptr, map->win_ptr, map->img.img, 0, 0);
	return (0);
}
