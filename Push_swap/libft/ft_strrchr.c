/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbadda <bbadda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 19:55:40 by bbadda            #+#    #+#             */
/*   Updated: 2023/12/31 11:33:14 by bbadda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int		i;
	char	*p;

	p = (char *)str;
	i = ft_strlen(p);
	while (i >= 0)
	{
		if (p[i] == (char)c)
			return (p + i);
		i--;
	}
	return (0);
}
