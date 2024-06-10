/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbadda <bbadda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 10:22:23 by bbadda            #+#    #+#             */
/*   Updated: 2024/06/04 11:18:16 by bbadda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	converts_to_bits(int pid, unsigned char character)
{
	unsigned int	bit;
	int				i;

	i = 8;
	while (i--)
	{
		bit = (character >> i & 1);
		if (bit == 0)
			kill(pid, SIGUSR1);
		else if (bit == 1)
			kill(pid, SIGUSR2);
		usleep(250);
	}
}

int	main(int ac, char *av[])
{
	int		i;

	if (ac == 3)
	{
		if (ft_atoi(av[1]) < 2)
			__error(2);
		i = 0;
		while (av[2][i])
		{
			converts_to_bits(ft_atoi(av[1]), av[2][i]);
			i++;
		}
	}
	else
		__error(0);
}
