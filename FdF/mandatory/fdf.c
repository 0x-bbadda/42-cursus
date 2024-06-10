/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbadda <bbadda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 01:40:34 by bbadda            #+#    #+#             */
/*   Updated: 2024/06/09 17:55:55 by bbadda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	__creat_window(t_map *map)
{
	map->mlx_ptr = mlx_init();
	map->win_ptr = mlx_new_window(map->mlx_ptr, WIDTH, HEIGHT, "MLX42");
	map->img.img = mlx_new_image(map->mlx_ptr, WIDTH, HEIGHT);
	map->img.addr = mlx_get_data_addr(map->img.img, &map->img.bpp,
			&map->img.size_line, &map->img.endian);
	map->x_offset = WIDTH / 2 + map->width / 2;
	map->y_offset = HEIGHT / 2 - map->height / 2;
}

void	check_the_map(char *str)
{
	t_int	init;

	init.i = 0;
	init.lenth = 0;
	init.fd1 = open(str, O_RDWR);
	if (init.fd1 == -1)
		__error(2, init.fd1);
	init.s = get_next_line(init.fd1);
	while (init.s)
	{
		init.str = ft_split(init.s, ' ');
		init.j = 0;
		while (init.str[init.j])
			init.j++;
		__free(init.str);
		if (init.i == 0)
			init.lenth = init.j;
		if (init.j != init.lenth)
			__error(3, init.fd1);
		free(init.s);
		init.s = get_next_line(init.fd1);
		init.i++;
	}
}

int	main(int ac, char **av)
{
	t_map	map;

	map.height = 0;
	if (ac == 2)
	{
		is_fdf_file(av[1]);
		check_the_map(av[1]);
		read_from_file(av[1], &map);
		__creat_window(&map);
		mlx_loop_hook(map.mlx_ptr, __draw_map, &map);
		mlx_hook(map.win_ptr, 2, 0, __key_hook, &map);
		mlx_hook(map.win_ptr, 17, 0, __handle, &map);
		mlx_loop(map.mlx_ptr);
	}
	else
		__error(0, 0);
}
