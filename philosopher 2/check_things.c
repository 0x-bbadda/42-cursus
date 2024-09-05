/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_things.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbadda <bbadda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 23:59:43 by bbadda            #+#    #+#             */
/*   Updated: 2024/09/03 13:36:21 by bbadda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_death_status(t_philo *each_philo)
{
	int	status;

	pthread_mutex_lock(&each_philo->info->should_die_m);
	status = each_philo->should_die;
	pthread_mutex_unlock(&each_philo->info->should_die_m);
	return (status);
}

int	check_finished_status(t_philo *each_philo)
{
	int	status;

	pthread_mutex_lock(&each_philo->info->finished_m);
	status = each_philo->info->finished;
	pthread_mutex_unlock(&each_philo->info->finished_m);
	return (status);
}

size_t	check_last_meal_status(t_philo *each_philo)
{
	size_t	last_meal;

	pthread_mutex_lock(&each_philo->info->last_meal_m);
	last_meal = each_philo->last_meal_time;
	pthread_mutex_unlock(&each_philo->info->last_meal_m);
	return (last_meal);
}

void	*__check_death(void *arg)
{
	t_philoinfo		*info;
	int			i;

	i = 0;
	int d = 0;
	info = (t_philoinfo *)arg;
	while (i++ < info->number_of_philos)
	{
		while (!d)
		{
			if (info->time_to_die < 
				get_msec_time() - check_last_meal_status(&info->philo[i]) && !info->is_die)
			{
				d = 1;
				mutex_print(&info->philo[i], "died");
				info->is_die =true;
				pthread_mutex_lock(&info->should_die_m);
				info->philo[i].should_die = true;
				pthread_mutex_unlock(&info->should_die_m);
				pthread_mutex_lock(&info->finished_m);
				info->finished = true;
				pthread_mutex_unlock(&info->finished_m);
			}
			usleep(100);
		}
	}
	return (NULL);
}

void	*__check_hunger(void *arg)
{
	t_philoinfo	*info;

	info = arg;
	while (!check_finished_status(info->philo))
	{
		if (info->eat == info->number_of_philos)
			info->finished = true;
	}
	return (NULL);
}