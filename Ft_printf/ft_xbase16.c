/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xbase16.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbadda <bbadda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 09:27:29 by bbadda            #+#    #+#             */
/*   Updated: 2024/01/10 10:54:22 by bbadda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_xbase16(unsigned long n, char c)
{
	int	count;

	count = 0;
	if (n >= 16)
	{
		count += ft_xbase16(n / 16, c);
		count += ft_xbase16(n % 16, c);
	}
	else if (n > 9)
	{
		n = n + c - 10;
		count += ft_putchar(n);
	}
	else if (n <= 9)
		count += ft_putchar(n + '0');
	return (count);
}
