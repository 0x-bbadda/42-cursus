/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbadda <bbadda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 12:58:14 by bbadda            #+#    #+#             */
/*   Updated: 2024/08/03 20:34:18 by bbadda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	take_fork(t_philo *philo, int ph)
{
	pthread_mutex_lock(&philo->info->forks[ph]);
	mutex_print(philo, "has taken a fork");
	
}

void	drop_fork(t_philo *philo, int ph1, int ph2)
{
	pthread_mutex_unlock(&philo->info->forks[ph1]);
	pthread_mutex_unlock(&philo->info->forks[ph2]);
}

void	my_own_sleep(long time)
{
	long start_time;
	
	start_time = get_msec_time();
	while(1)
	{
		if (get_msec_time() - start_time > time)
			break ;
		usleep(150);
	}
}

void	*__check_death(void *arg)
{
	t_philo	*philo;

	philo = arg;
	while (!philo->info->finished)
	{
		if ((philo->last_meal_time + philo->info->time_to_die) < get_msec_time())
		{
			mutex_print(philo, "died");
			philo->should_die = true;
			philo->info->finished = true;
		}
		usleep(100);
	}
	return (NULL);
}

void	*__check_hunger(void *arg)
{
	t_philoinfo	*info;

	info = arg;
	while (!info->finished)
	{
		if (info->eat == info->number_of_philos)
			info->finished = true;
	}
	return (NULL);
}

void	*ft_routine(void *philo)
{
	t_philo		*each_philo;
	int			right_fork;
	int			left_fork;

	each_philo = (t_philo *)philo;
	while (!each_philo->should_die && !each_philo->info->finished)
	{
		right_fork = each_philo->ID;
		left_fork = (each_philo->ID + 1) % each_philo->info->number_of_philos;
		take_fork(each_philo, right_fork);
		if (each_philo->info->number_of_philos == 1)
		{
			my_own_sleep(each_philo->info->time_to_die);
			break ;
		}
		take_fork(each_philo, left_fork);
		eating(each_philo);
		drop_fork(each_philo, right_fork, left_fork);
		sleep_and_then_think(each_philo);
	}
	return (NULL);
}

void	__create_threads_and_philos(t_philoinfo *info)
{
	pthread_t	monitor_thread;
	int			i;

	i = 0;
	info->start_time = get_msec_time();
	while (i < info->number_of_philos)
	{
		init_all_philos(info, i);
		pthread_create(&info->philo[i].thread, NULL, ft_routine, &info->philo[i]);
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
