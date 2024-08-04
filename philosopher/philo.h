/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbadda <bbadda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 12:16:13 by bbadda            #+#    #+#             */
/*   Updated: 2024/08/03 20:05:46 by bbadda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
#define PHILO_H

# include <stdio.h>
# include <string.h>
# include <string.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>
# include <unistd.h>
# include <stdbool.h>

typedef struct s_philoinfo t_philoinfo;

typedef struct s_forks
{
	int fork_ID;
	pthread_mutex_t *fork;
}t_forks;

typedef struct s_philo
{
	int			ID;
	int			ate;
	size_t		should_die;
	size_t		last_meal_time;
	pthread_t	thread;
	t_philoinfo	*info;
}t_philo;

typedef struct s_philoinfo
{
	int				number_of_philos;
	long			time_to_die;
	long			time_to_eat;
	long			time_to_sleep;
	long			n_time_should_eat;
	int				finished;
	int				eat;
	t_philo			*philo;
	pthread_mutex_t *forks;
	pthread_mutex_t finish_lock;
	size_t 			start_time;
}t_philoinfo;

int				__check_info(t_philoinfo info, int ac);
//--------------------init_data-----------------------------//
void			__init_args(t_philoinfo *ph, char **av, int ac);
void			init_all_philos(t_philoinfo *info, int i);
void			__creat_mutex(t_philoinfo *ph);
void			__create_threads_and_philos(t_philoinfo *info);
void			__check_args(int ac);
//----------------------------------------------------------//
void			__error(int index);
int 		   	ft_atoi(const char *str);
void			*__calloc(size_t count, size_t size);
void			*ft_routine(void *philos);
long		   	get_msec_time(void);
void			*__is_died(void *philo);
long			get_msec_time(void);
void			mutex_print(t_philo *philo, char *message);
void    		eating(t_philo *each_philo);
void			my_own_sleep(long time);
void			sleep_and_then_think(t_philo *philo);


#endif