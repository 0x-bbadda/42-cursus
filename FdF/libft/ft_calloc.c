/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbadda <bbadda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 07:13:58 by bbadda            #+#    #+#             */
/*   Updated: 2023/12/31 09:59:46 by bbadda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t n, size_t size)
{
	size_t	size_total;
	size_t	i;
	void	*ptr;

	i = 0;
	size_total = (n * size);
	ptr = malloc(size_total);
	if (!ptr)
		return (NULL);
	while (i < size_total)
	{
		((char *)ptr)[i] = 0;
		i++;
	}
	return (ptr);
}
