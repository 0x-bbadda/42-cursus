/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbadda <bbadda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 17:59:52 by bbadda            #+#    #+#             */
/*   Updated: 2024/08/03 18:33:19 by bbadda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	__join_and_free(t_philoinfo *info)
{
	int	i;

	i = 0;
	while (i < info->number_of_philos)
		pthread_join(info->philo[i++].thread, NULL);
	free(info->philo);
	i = 0;
	while (i < info->number_of_philos)
		pthread_mutex_destroy(&info->forks[i++]);
	pthread_mutex_destroy(&info->finish_lock);
	free(info->forks);
	free(info);
}

int	main(int ac, char *av[])
{
	t_philoinfo *info;

	__check_args(ac);
	info = __calloc(1, sizeof(*info));
	__init_args(info, av, ac);
	if (__check_info(*info, ac))
		return (1);
	info->philo = __calloc(info->number_of_philos, sizeof(t_philo));
	info->forks = __calloc(info->number_of_philos, sizeof(pthread_mutex_t));
	if (!info->philo || !info->forks)
		return (1);
	info->finished = false;
	info->eat = 0;
	__creat_mutex(info);
	__create_threads_and_philos(info);
	__join_and_free(info);
	return (0);
}
