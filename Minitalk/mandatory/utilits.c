/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilits.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbadda <bbadda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 11:52:20 by bbadda            #+#    #+#             */
/*   Updated: 2024/06/05 11:34:30 by bbadda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_putchar(char c)
{
	write (1, &c, 1);
}

int	ft_atoi(const char *str)
{
	int					i;
	int					s;
	unsigned long long	r;

	r = 0;
	s = 1;
	i = 0;
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-')
		s = -s;
	if ((*str == '+' || *str == '-'))
		str++;
	while (str[i])
	{
		if (str[i] > '9' || str[i] < '0')
			__error(1);
		i++;
	}
	while (*str >= '0' && *str <= '9')
	{
		r = (r * 10) + (*str - 48);
		str++;
	}
	return (r * s);
}

void	ft_putnbr(int n)
{
	char	nbr;

	if (n < 0)
	{
		write(1, "-", 1);
		n *= -1;
	}
	if (n == -2147483648)
	{
		write(1, "2", 1);
		ft_putnbr(147483648);
	}
	else if (n <= 9)
	{
		nbr = n + '0';
		write(1, &nbr, 1);
	}
	else
	{
		ft_putnbr(n / 10);
		ft_putchar(n % 10 + '0');
	}
}

size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	while (str[len])
	{
		len++;
	}
	return (len);
}

void	__error(int x)
{
	if (x == 0)
	{
		write(1, "❌Incorrect number of arguments, expected 2", 45);
		exit(0);
	}
	if (x == 1)
	{
		write(1, "❌Error: PID invalid!\n", 23);
		write(1, "The server PID has only numbers\n", 32);
		exit(0);
	}
	if (x == 2)
	{
		write(1, "❌Error: PID invalid!\n", 23);
		write(1, "The server PID incorrect\n", 26);
		exit(0);
	}
}
