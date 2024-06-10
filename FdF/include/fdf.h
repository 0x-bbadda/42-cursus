/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbadda <bbadda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 01:51:11 by bbadda            #+#    #+#             */
/*   Updated: 2024/06/08 17:50:06 by bbadda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "mlx.h"
# include "../libft/libft.h"
# include "errors.h"
# include "tools.h"
# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <stdbool.h>
# include <fcntl.h>
# include <math.h>

# define WIDTH 1900
# define HEIGHT 1000

typedef struct s_int
{
	int		lenth;
	int		i;
	int		j;
	int		sr;
	int		fd1;
	int		fd2;
	char	**str;
	char	*s;
}t_int;

typedef struct s_point
{
	float	y;
	float	x;
	float	z;
	float	p;
	int		sx;
	int		sy;
	int		i;
	t_delta	d;
	int		color;
}t_point;

typedef struct s_map
{
	t_point	**p;
	void	*mlx_ptr;
	void	*win_ptr;
	int		**map;
	int		height;
	int		width;
	t_img	img;
	float	zoom;
	int		x_offset;
	int		y_offset;
	int		zoom_offset;
}t_map;

// ..................errors_functions........................//
void		is_fdf_file(const char *s);
// ..................setup_functions........................//
void		read_from_file(char *av, t_map *map);
void		__free(char **str);
void		__bresnham(t_map *map, t_point p1, t_point p2);
void		__bresnham2(t_map *map, t_point p1, t_point p2);
void		my_mlx_pixel_put(t_map *data, int x, int y, int color);
void		__creat_window(t_map *map);
int			__key_hook(int key, t_map *map);
int			__handle(t_map *map);
int			__draw_map(t_map *map);
void		get_points(t_map *map, char **str, int fd);
void		get_points_scales(t_map *map);
int			do_gradiant(int color_p1, int color_p2, float pos);
void		clear_window(t_map *map);
// ..................utils_functions........................//
float		__abs(float p2, float p1);
int			ft_sign(int x);
void		abs_sign(t_point *info, t_point *p1, t_point *p2);
int			start_lenth(char *str);
int			hex_to_int(char *str);
void		__scale(t_map *map, int s);
void		__error(int index, int fd);
void		__error2(int index);
int			__max(t_map *map);
int			__min(t_map *map);

#endif