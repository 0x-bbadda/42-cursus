/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbadda <bbadda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 12:58:14 by bbadda            #+#    #+#             */
/*   Updated: 2024/09/03 13:31:49 by bbadda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	sleep_and_then_think(t_philo *philo)
{
	mutex_print(philo, "is sleeping");
	my_own_sleep(philo->info->time_to_sleep);
	mutex_print(philo, "is thinking");
}

void	eating(t_philo *each_philo)
{
	mutex_print(each_philo, "is eating");
	my_own_sleep(each_philo->info->time_to_eat);
	pthread_mutex_lock(&each_philo->info->last_meal_m);
	each_philo->last_meal_time = get_msec_time();
	pthread_mutex_unlock(&each_philo->info->last_meal_m);
	pthread_mutex_lock(&each_philo->ate_m);
	each_philo->ate++;
	pthread_mutex_unlock(&each_philo->ate_m);
	if (each_philo->ate == each_philo->info->n_time_should_eat && each_philo->ate != -1)
	{
		pthread_mutex_lock(&each_philo->info->all_ate_m);
		each_philo->info->all_ate++;
		pthread_mutex_unlock(&each_philo->info->all_ate_m);
		each_philo->ate = -1;
	}
}

static void	take_fork(t_philo *philo, int fork)
{
	if (fork != -1)
	{
		pthread_mutex_lock(&philo->info->forks[fork]);
		mutex_print(philo, "has taken a fork");
	}
}

static void	drop_fork(t_philo *philo, int fork1, int fork2)
{
	pthread_mutex_unlock(&philo->info->forks[fork1]);
	pthread_mutex_unlock(&philo->info->forks[fork2]);
}

void	one_philo(t_philo *philo)
{
	take_fork(philo, 1);
	usleep(1000000);
}

void	*ft_routine(void *philo)
{
	t_philo		*each_philo;
	int			right_fork;
	int			left_fork;

	each_philo = (t_philo *)philo;
	if(each_philo->info->number_of_philos == 1)
	{
		one_philo(each_philo);
		return NULL;
	}
	if (each_philo->id % 2 == 0)
	{
		mutex_print(philo, "is thinking");
		my_own_sleep(each_philo->info->time_to_sleep);
	}
	while (!check_death_and_hunger_status(each_philo))
	{
		right_fork = each_philo->id;
		if (each_philo->info->number_of_philos == 1)
			left_fork = -1;
		else
			left_fork = (each_philo->id + 1) % each_philo->info->number_of_philos;
		take_fork(each_philo, right_fork);
		take_fork(each_philo, left_fork);
		eating(each_philo);
		drop_fork(each_philo, right_fork, left_fork);
		sleep_and_then_think(each_philo);
	}
	pthread_mutex_unlock(&each_philo->info->should_die_m);
	pthread_mutex_unlock(&each_philo->info->finished_m);
	return (NULL);
}
