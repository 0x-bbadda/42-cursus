/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_things.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbadda <bbadda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 16:02:36 by bbadda            #+#    #+#             */
/*   Updated: 2024/09/06 23:44:35 by bbadda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*one_philo(void *info)
{
	t_philoinfo	*ph;

	ph = (t_philoinfo *)info;
	printf("%d %d %s\n", 0, 1, "is thinking");
	printf("%d %d %s\n", 0, 1, "has taken a fork");
	my_own_sleep(ph->time_to_die);
	printf("%lu %d %s\n", ph->time_to_die, 1, "is died");
	return (NULL);
}

void	__create_threads_and_philos(t_philoinfo *info)
{
	int	i;

	i = 0;
	info->start_time = get_msec_time();
	if (info->number_of_philos == 1)
	{
		pthread_create(&info->philo[i].thread, NULL, one_philo, 
			info);
		return ;
	}
	while (i < info->number_of_philos)
	{
		init_all_philos(info, i);
		pthread_create(&info->philo[i].thread, NULL, ft_routine, 
			&info->philo[i]);
		i++;
	}
}

void	__creat_mutex(t_philoinfo *info)
{
	int	i;

	i = -1;
	pthread_mutex_init(&info->is_die_m, NULL);
	pthread_mutex_init(&info->print_m, NULL);
	pthread_mutex_init(&info->all_ate_m, NULL);
	pthread_mutex_init(&info->should_die_m, NULL);
	pthread_mutex_init(&info->finished_m, NULL);
	pthread_mutex_init(&info->last_meal_m, NULL);
	while (++i < info->number_of_philos)
		pthread_mutex_init(&info->forks[i], NULL);
}
