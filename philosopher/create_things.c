/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_things.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbadda <bbadda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 16:02:36 by bbadda            #+#    #+#             */
/*   Updated: 2024/09/03 13:34:56 by bbadda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	__create_threads_and_philos(t_philoinfo *info)
{
	pthread_t	monitor_thread;
	int			i;

	i = 0;
	info->start_time = get_msec_time();
	while (i < info->number_of_philos)
	{
		init_all_philos(info, i);
		pthread_create(&info->philo[i].thread, NULL, 
			ft_routine, &info->philo[i]);
		pthread_create(&monitor_thread, NULL, __check_death, &info->philo[i]);
		pthread_detach(monitor_thread);
		i++;
		usleep(100);
	}
	if (info->n_time_should_eat >= 0)
	{
		pthread_create(&monitor_thread, NULL, __check_hunger, info);
		pthread_detach(monitor_thread);
	}
}

void	__creat_mutex(t_philoinfo *info)
{
	int	i;

	i = -1;
	pthread_mutex_init(&info->print_m, NULL);
	pthread_mutex_init(&info->eat_m, NULL);
	pthread_mutex_init(&info->should_die_m, NULL);
	pthread_mutex_init(&info->finished_m, NULL);
	pthread_mutex_init(&info->last_meal_m, NULL);
	while (++i < info->number_of_philos)
		pthread_mutex_init(&info->forks[i], NULL);
}
