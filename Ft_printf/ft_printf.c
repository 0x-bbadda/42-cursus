/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbadda <bbadda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 11:12:17 by bbadda            #+#    #+#             */
/*   Updated: 2024/01/25 10:04:24 by bbadda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	__format( va_list ap, char format)
{
	int	count;

	count = 0;
	if (format == 'c')
		count += ft_putchar(va_arg(ap, int));
	else if (format == 's')
		count += ft_putstr(va_arg(ap, char *));
	else if (format == 'p')
	{
		count += ft_putstr("0x");
		count += ft_xbase16(va_arg(ap, unsigned long), 'a');
	}
	else if (format == 'd' || format == 'i')
		count += ft_putnbr(va_arg(ap, int));
	else if (format == 'u')
		count += ft_unsigned_nbr(va_arg(ap, unsigned int));
	else if (format == 'x')
		count += ft_xbase16(va_arg(ap, unsigned int), 'a');
	else if (format == 'X')
		count += ft_xbase16(va_arg(ap, unsigned int), 'A');
	else if (format == '%')
		count += ft_putchar(format);
	else
		count += ft_putchar(format);
	return (count);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		count;
	va_list	ap;

	if (write(1, "", 0) == -1)
		return (-1);
	va_start(ap, format);
	count = 0;
	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			if (!format[i])
				return (count);
			count += __format(ap, format[i]);
		}
		else
			count += ft_putchar(format[i]);
		i++;
	}
	va_end(ap);
	return (count);
}
