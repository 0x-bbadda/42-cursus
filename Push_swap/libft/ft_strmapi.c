/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbadda <bbadda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 16:41:11 by bbadda            #+#    #+#             */
/*   Updated: 2024/01/01 13:25:30 by bbadda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *str, char (*f)(unsigned int, char))
{
	size_t	i;
	char	*new_str;
	size_t	len;

	i = 0;
	if (!str || !f)
		return (NULL);
	len = ft_strlen(str);
	new_str = (char *)malloc(sizeof(char) * (len + 1));
	if (new_str == NULL)
		return (NULL);
	while (i < len)
	{
		new_str[i] = f(i, str[i]);
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}
