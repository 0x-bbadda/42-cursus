/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbadda <bbadda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 13:06:33 by bbadda            #+#    #+#             */
/*   Updated: 2024/08/02 00:23:27 by bbadda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static	int	__strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

static int	print_err(char *err)
{
	write(STDERR_FILENO, err, __strlen(err));
	return (1);
}

int	__check_info(t_philoinfo info, int ac)
{
	if (ac == 6 && info.n_time_should_eat <= 0)
		return (print_err("ERROR: wrong num of must eat\n"));
	if (info.number_of_philos < 0)
		return (print_err("ERROR: wrong num of philo\n"));
	if (info.time_to_die < 60)
		return (print_err("ERROR: wrong time to die\n"));
	if (info.time_to_eat < 60)
		return (print_err("ERROR: wrong time to eat\n"));
	if (info.time_to_sleep < 60)
		return (print_err("ERROR: wrong time to sleep\n"));
	return (0);
}

void	__error(int index)
{
	if (index == 0)
	{
		printf("Number of elementes incorrect !\n");
		exit(0);
	}
	if (index == 1)
	{
		printf("The Arguments contains only numbers !\n");
		exit(0);
	}
}

static void	__bzero(void *s, size_t n)
{
	while (n--)
		*((unsigned char *)(s + n)) = 0;
}

void	*__calloc(size_t count, size_t size)
{
	void	*res;

	res = malloc(size * count);
	if (!res)
		return (0);
	__bzero(res, size * count);
	return (res);
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

long	get_msec_time(void)
{
	struct	timeval time;
	long	msec_time;

	gettimeofday(&time, NULL);
	msec_time = (time.tv_sec * 1000) + (time.tv_usec / 1000); 
	return msec_time;
}