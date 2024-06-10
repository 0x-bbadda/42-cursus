/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbadda <bbadda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 18:37:19 by bbadda            #+#    #+#             */
/*   Updated: 2023/12/31 11:25:04 by bbadda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	int		i;
	char	*p;

	p = (char *)str;
	i = 0;
	while (p[i] != '\0')
	{
		if (p[i] == (char)c)
			return (p + i);
		i++;
	}
	if (p[i] == (char)c)
		return (p + i);
	return (0);
}
