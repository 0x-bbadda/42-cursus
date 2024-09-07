/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_things.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbadda <bbadda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 09:47:24 by bbadda            #+#    #+#             */
/*   Updated: 2024/09/07 12:26:08 by bbadda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	__init_args(t_philoinfo *info, char **av, int ac)
{
	info->number_of_philos = ft_atoi(av[1]);
	info->time_to_die = ft_atoi(av[2]);
	info->time_to_eat = ft_atoi(av[3]);
	info->time_to_sleep = ft_atoi(av[4]);
	if (ac == 6)
		info->n_time_should_eat = ft_atoi(av[5]);
	else
		info->n_time_should_eat = -1;
}

void	init_all_philos(t_philoinfo *info, int i)
{
	info->philo[i].id = i + 1;
	info->philo[i].right_fork = i;
	if (info->number_of_philos != 1)
		info->philo[i].left_fork = (i + 1) % info->number_of_philos; 
	info->philo[i].info = info;
	info->philo[i].last_meal_time = info->start_time;
	info->philo[i].should_die = false;
	info->philo[i].ate = 0;
	pthread_mutex_init(&info->philo[i].ate_m, NULL);
}
