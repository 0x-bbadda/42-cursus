/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbadda <bbadda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 10:03:10 by bbadda            #+#    #+#             */
/*   Updated: 2024/01/10 10:12:34 by bbadda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	if (str == NULL)
	{
		ft_putstr("(null)");
		return (6);
	}
	if (!str)
		return (0);
	while (str[i])
	{
		count += ft_putchar(str[i]);
		i++;
	}
	return (count);
}
