/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbadda <bbadda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 09:45:09 by bbadda            #+#    #+#             */
/*   Updated: 2024/08/03 20:07:23 by bbadda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	mutex_print(t_philo *philo, char *message)
{
	pthread_mutex_lock(&philo->info->finish_lock);
	if (!philo->info->finished)
		printf("%lu %d %s\n", get_msec_time() - philo->info->start_time, philo->ID + 1, message);
	pthread_mutex_unlock(&philo->info->finish_lock);
}
