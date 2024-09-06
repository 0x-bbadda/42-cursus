/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_things.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbadda <bbadda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 13:08:52 by bbadda            #+#    #+#             */
/*   Updated: 2024/09/06 23:49:19 by bbadda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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

static int	print_err(char *err)
{
	write(STDERR_FILENO, err, __strlen(err));
	return (1);
}

int	__check_info(t_philoinfo info, int ac)
{
	if (ac == 6 && info.n_time_should_eat <= 0)
		return (print_err("ERROR: wrong num of must eat\n"));
	if (info.number_of_philos <= 0)
		return (print_err("ERROR: wrong num of philo\n"));
	if (info.time_to_die < 60)
		return (print_err("ERROR: wrong time to die\n"));
	if (info.time_to_eat < 60)
		return (print_err("ERROR: wrong time to eat\n"));
	if (info.time_to_sleep < 60)
		return (print_err("ERROR: wrong time to sleep\n"));
	return (0);
}

void	mutex_print(t_philo *philo, char *message)
{
	pthread_mutex_lock(&philo->info->finished_m);
	if (!check_death_and_hunger_status(philo))
	{
		pthread_mutex_lock(&philo->info->print_m);
		printf("%lu %d %s\n", get_msec_time() - philo->info->start_time, 
			philo->id, message);
		if (strcmp(message, "died") != 0)
			pthread_mutex_unlock(&philo->info->print_m);
		pthread_mutex_unlock(&philo->info->finished_m);
	}
	else
		pthread_mutex_unlock(&philo->info->finished_m);
}
