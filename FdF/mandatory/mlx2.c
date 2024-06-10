/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbadda <bbadda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 13:26:07 by bbadda            #+#    #+#             */
/*   Updated: 2024/06/09 13:03:11 by bbadda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	is_fdf_file(const char *s)
{
	size_t	len;

	len = ft_strlen(s);
	if (len < 5 || ft_strncmp(s + (len - 4), ".fdf", len - 4) != 0)
		__error2(7);
}

int	ft_sign(int x)
{
	if (x > 0)
		return (1);
	else if (x < 0)
		return (-1);
	else
		return (0);
}

void	abs_sign(t_point *info, t_point *p1, t_point *p2)
{
	info->d.dx = __abs(p2->x, p1->x);
	info->d.dy = __abs(p2->y, p1->y);
	info->sx = ft_sign(p2->x - p1->x);
	info->sy = ft_sign(p2->y - p1->y);
}

void	__bresnham2(t_map *map, t_point p1, t_point p2)
{
	t_point	info;
	int		i;

	i = -1;
	info.x = p1.x;
	info.y = p1.y;
	abs_sign(&info, &p1, &p2);
	info.p = (2 * info.d.dx) - info.d.dy;
	while (++i <= info.d.dy)
	{
		info.color = do_gradiant(p1.color, p2.color, (float)i / info.d.dy);
		my_mlx_pixel_put(map, (int)info.x, (int)info.y, info.color);
		if (p1.x == p2.x && p1.y == p2.y)
			break ;
		while (info.p >= 0)
		{
			info.p -= 2 * info.d.dy;
			info.x += info.sx;
		}
		info.p += 2 * info.d.dx;
		info.y += info.sy;
	}
}

void	clear_window(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < HEIGHT)
	{
		j = 0;
		while (j < WIDTH)
		{
			my_mlx_pixel_put(map, j, i, 0);
			j++;
		}
		i++;
	}
}
