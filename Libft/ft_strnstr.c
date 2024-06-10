/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbadda <bbadda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 07:27:43 by bbadda            #+#    #+#             */
/*   Updated: 2024/01/04 17:35:48 by bbadda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *b_str, const char *l_str, size_t len)
{
	size_t	j;
	size_t	i;

	i = 0;
	j = 0;
	if (!b_str && len == 0 && l_str)
		return (0);
	if (l_str[i] == '\0')
		return ((char *)b_str); 
	while (b_str[i] != '\0' && i < len)
	{
		j = 0;
		while (l_str[j] == b_str[i + j] && (j + i) < len)
		{
			if (l_str[j + 1] == '\0')
				return ((char *)(b_str + i));
			j++;
		}
		i++;
	}
	return (0);
}
