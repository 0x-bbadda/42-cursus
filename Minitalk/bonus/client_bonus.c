/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbadda <bbadda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 10:22:23 by bbadda            #+#    #+#             */
/*   Updated: 2024/06/06 10:59:15 by bbadda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	converts_to_bits(int pid, unsigned char character)
{
	unsigned int	bit;
	int				i;

	i = 8;
	while (i--)
	{
		bit = (character >> i & 1);
		if (bit == 0)
		{
			if (kill(pid, SIGUSR1))
				exit(0);
		}
		else if (bit == 1)
		{
			if (kill(pid, SIGUSR2))
				exit(0);
		}
		usleep(150);
	}
}

static void	get_handler(int sign)
{
	if (sign == SIGUSR2)
	{
		write(1, "\033[0;32mMESSAGE RECIEVED!\033[0m\n", 30);
		exit(0);
	}
}

int	main(int ac, char *av[])
{
	struct sigaction	act;
	int					i;

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
		converts_to_bits(ft_atoi(av[1]), 0);
		act.sa_handler = get_handler;
		sigaction(SIGUSR2, &act, NULL);
		while (1)
			pause();
	}
	else
		__error(0);
}
