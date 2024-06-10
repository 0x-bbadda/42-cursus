/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_keys.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbadda <bbadda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 12:05:51 by bbadda            #+#    #+#             */
/*   Updated: 2024/06/09 17:42:48 by bbadda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int	__key_hook(int key, t_map *map)
{
	if (key == 53)
		__handle(map);
	if (key == UP)
		map->y_offset -= 10;
	if (key == DOWN)
		map->y_offset += 10;
	if (key == RIGHT)
		map->x_offset += 10;
	if (key == LEFT)
		map->x_offset -= 10;
	return (0);
}

int	__handle(t_map *map)
{
	mlx_destroy_image(map->mlx_ptr, map->img.img);
	mlx_destroy_window(map->mlx_ptr, map->win_ptr);
	exit(0);
}
