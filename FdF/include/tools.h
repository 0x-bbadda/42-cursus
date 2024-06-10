/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbadda <bbadda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 13:02:28 by bbadda            #+#    #+#             */
/*   Updated: 2024/06/07 17:07:38 by bbadda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOOLS_H
# define TOOLS_H

# define ESC_KEY 53
# define UP 126
# define DOWN 125
# define RIGHT 124
# define LEFT 123

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bpp;
	int		size_line;
	int		endian;
}t_img;

typedef struct s_delta
{
	float	dx;
	float	dy;
	int		color_p1;
	int		color_p2;
}t_delta;

typedef struct s_color 
{
	int	r;
	int	g;
	int	b;
}t_color;

#endif