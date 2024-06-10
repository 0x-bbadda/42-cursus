/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned_nbr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbadda <bbadda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 16:28:58 by bbadda            #+#    #+#             */
/*   Updated: 2024/01/10 10:05:06 by bbadda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_unsigned_nbr(unsigned int n)
{
	char	nbr;
	int		count;

	count = 0;
	if (n <= 9)
	{
		nbr = n + '0';
		count += ft_putchar(nbr);
	}
	else
	{
		count += ft_unsigned_nbr(n / 10);
		count += ft_putchar(n % 10 + '0');
	}
	return (count);
}
