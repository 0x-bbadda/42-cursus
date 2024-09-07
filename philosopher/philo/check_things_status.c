/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_things_status.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbadda <bbadda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 12:30:12 by bbadda            #+#    #+#             */
/*   Updated: 2024/09/07 12:34:41 by bbadda           ###   ########.fr       */
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

int	check_death_and_hunger_status(t_philo *each_philo)
{
	int	status;

	pthread_mutex_lock(&each_philo->info->is_die_m);
	status = each_philo->info->is_die;
	pthread_mutex_unlock(&each_philo->info->is_die_m);
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
