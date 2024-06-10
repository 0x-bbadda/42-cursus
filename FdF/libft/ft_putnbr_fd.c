/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbadda <bbadda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 18:05:20 by bbadda            #+#    #+#             */
/*   Updated: 2024/01/01 13:28:24 by bbadda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	nbr;

	if (n < 0)
	{
		write(fd, "-", 1);
		n *= -1;
	}
	if (n == -2147483648)
	{
		write(fd, "2", 1);
		ft_putnbr_fd(147483648, fd);
	}
	else if (n <= 9)
	{
		nbr = n + '0';
		write(fd, &nbr, 1);
	}
	else
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putchar_fd(n % 10 + '0', fd);
	}
}
