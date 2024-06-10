/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbadda <bbadda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 15:52:12 by bbadda            #+#    #+#             */
/*   Updated: 2024/06/06 10:38:08 by bbadda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

int	converts_to_decimal(char *str)
{
	int	i;
	int	digit;
	int	decimal;
	int	base;

	base = 1;
	digit = 0;
	decimal = 0;
	i = 7;
	while (i >= 0)
	{
		digit = str[i] - '0';
		decimal += digit * base;
		base *= 2;
		i--;
	}
	return (decimal);
}

static void	print(char *str, int *x, int pid_c)
{
	if (ft_strlen(str) == 8)
	{
		ft_putchar(converts_to_decimal(str));
		if (converts_to_decimal(str) == '\0')
		{
			usleep(250);
			kill(pid_c, SIGUSR2);
		}
		*x = 0;
		str[0] = '\0';
	}
}

void	get_sing(int sign, siginfo_t *info, void *con)
{
	static char	str[9];
	static int	x;
	static int	pid_c;

	(void)con;
	if (pid_c != 0 && info->si_pid != pid_c)
	{
		str[0] = '\0';
		x = 0;
		pid_c = info->si_pid;
	}
	else 
		pid_c = info->si_pid;
	if (sign == SIGUSR1)
		str[x++] = '0';
	str[x] = '\0';
	if (sign == SIGUSR2)
		str[x++] = '1';
	str[x] = '\0';
	print(str, &x, info->si_pid);
}

int	main(void)
{
	struct sigaction	act;
	int					pid;

	pid = getpid();
	write(1, "\033[0;35mServer PID: \033[0m", 25);
	write(1, "\033[0;35m[\033[0m", 13);
	ft_putnbr(pid);
	write(1, "\033[0;35m]\033[0m\n\n", 15);
	write(1, "\033[0;35mPRINT AREA \033[0m", 23);
	write(1, "\033[0;35m * * * * * * * * * * * * * * * *\033[0m\n", 45);
	act.sa_flags = SA_SIGINFO;
	act.sa_sigaction = get_sing;
	sigaction(SIGUSR1, &act, NULL);
	sigaction(SIGUSR2, &act, NULL);
	while (1)
		pause();
}
