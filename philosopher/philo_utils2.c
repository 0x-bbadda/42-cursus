/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbadda <bbadda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 09:45:09 by bbadda            #+#    #+#             */
/*   Updated: 2024/09/03 13:34:11 by bbadda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	my_own_sleep(long time)
{
	long	start_time;

	start_time = get_msec_time();
	while (1)
	{
		if (get_msec_time() - start_time > time)
			break ;
		usleep(150);
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
