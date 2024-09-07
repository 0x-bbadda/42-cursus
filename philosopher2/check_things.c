/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_things.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbadda <bbadda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 23:59:43 by bbadda            #+#    #+#             */
/*   Updated: 2024/09/07 12:34:33 by bbadda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	__check_hunger(void *arg)
{
	t_philoinfo	*info;

	info = arg;
	if (info->n_time_should_eat > 0 && !info->is_die)
	{
		if (info->all_ate == info->number_of_philos)
		{
			pthread_mutex_lock(&info->finished_m);
			info->finished = true;
			pthread_mutex_unlock(&info->finished_m);
		}
	}
}

static void	__check_death(void *arg)
{
	t_philo		*philo;
	int			i;

	philo = arg;
	i = 0;
	if (philo->info->time_to_die < get_msec_time() - 
		(long)check_last_meal_status(philo) && !philo->info->is_die)
	{
		pthread_mutex_lock(&philo->info->should_die_m);
		philo->should_die = true;
		pthread_mutex_unlock(&philo->info->should_die_m);
	}
}

static int	helper_function(t_philoinfo *info)
{
	int	i;

	i = 0;
	while (i < info->number_of_philos)
	{
		__check_hunger(info);
		__check_death(&info->philo[i]);
		if (info->philo[i].should_die || info->finished)
		{
			pthread_mutex_lock(&info->is_die_m);
			info->is_die = true;
			pthread_mutex_unlock(&info->is_die_m);
			if (info->philo[i].should_die)
			{
				pthread_mutex_lock(&(info->philo[i].info->print_m));
				printf("\033[0;31m%lu %d died\n", get_msec_time() - 
					info->philo[i].info->start_time, info->philo[i].id);
				pthread_mutex_unlock(&info->philo[i].info->print_m);
			}
			return (1);
		}
		i++;
	}
	return (0);
}

void	*__check_death_and_hunger(void *arg)
{
	t_philoinfo		*info;
	int				i;
	int				d;

	i = 0;
	d = 0;
	info = (t_philoinfo *)arg;
	while (!d)
	{
		i = 0;
		d = helper_function(info);
	}
	return (NULL);
}
