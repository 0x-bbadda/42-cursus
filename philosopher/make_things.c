/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_things.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbadda <bbadda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 16:02:36 by bbadda            #+#    #+#             */
/*   Updated: 2024/08/03 20:15:06 by bbadda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    eating(t_philo *each_philo)
{
	mutex_print(each_philo, "is eating");
	my_own_sleep(each_philo->info->time_to_eat);
	each_philo->last_meal_time = get_msec_time();
	each_philo->ate++;
	if (each_philo->ate == each_philo->info->n_time_should_eat)
        each_philo->info->eat++;
}

void	sleep_and_then_think(t_philo *philo)
{
	mutex_print(philo, "is sleeping");
    my_own_sleep(philo->info->time_to_sleep);
	mutex_print(philo, "is thinking");
}