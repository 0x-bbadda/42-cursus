/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbadda <bbadda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 01:22:09 by bbadda            #+#    #+#             */
/*   Updated: 2024/01/01 14:42:06 by bbadda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_cmp(size_t dst, size_t src, size_t dst_l)
{
	if (dst < dst_l)
		return (src + dst);
	else
		return (src + dst_l);
}

size_t	ft_strlcat(char *dst, const char *src, size_t dst_l)
{
	size_t	dst_len;
	size_t	src_len;
	size_t	t;
	size_t	i;

	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	t = ft_cmp(dst_len, src_len, dst_l);
	i = 0;
	while (src[i] && (dst_len + i) < dst_l - 1 && dst_l > 0)
	{
		dst[dst_len + i] = src[i];
		i++;
	}
	dst[dst_len + i] = '\0';
	return (t);
}
