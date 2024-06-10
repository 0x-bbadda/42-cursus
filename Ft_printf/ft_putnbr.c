/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbadda <bbadda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 08:36:59 by bbadda            #+#    #+#             */
/*   Updated: 2024/01/10 10:05:53 by bbadda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int n)
{
	char	nbr;
	int		count;

	count = 0;
	if (n < 0)
	{
		count += ft_putchar('-');
		n *= -1;
	}
	if (n == -2147483648)
	{
		count += ft_putchar('2');
		count += ft_putnbr(147483648);
	}
	else if (n <= 9)
	{
		nbr = n + '0';
		count += ft_putchar(nbr);
	}
	else
	{
		count += ft_putnbr(n / 10);
		count += ft_putchar(n % 10 + '0');
	}
	return (count);
}
