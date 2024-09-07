/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbadda <bbadda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 09:45:09 by bbadda            #+#    #+#             */
/*   Updated: 2024/09/07 12:27:12 by bbadda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	my_own_sleep(t_philo *philo, long time)
{
	long	start_time;

	start_time = get_msec_time();
	while (1)
	{
		if (check_death_and_hunger_status(philo))
			break ;
		if (get_msec_time() - start_time > time)
			break ;
		usleep(300);
	}
}

long	get_msec_time(void)
{
	struct timeval	time;
	long			msec_time;

	gettimeofday(&time, NULL);
	msec_time = (time.tv_sec * 1000) + (time.tv_usec / 1000); 
	return (msec_time);
}
