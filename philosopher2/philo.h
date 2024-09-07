/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbadda <bbadda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 12:16:13 by bbadda            #+#    #+#             */
/*   Updated: 2024/09/07 12:42:06 by bbadda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <string.h>
# include <string.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>
# include <unistd.h>
# include <stdbool.h>

typedef struct s_philoinfo	t_philoinfo;

typedef struct s_philo
{
	int				id;
	int				ate;
	size_t			should_die;
	size_t			last_meal_time;
	int				right_fork;
	int				left_fork;
	pthread_t		thread;
	pthread_mutex_t	ate_m;
	t_philoinfo		*info;
}t_philo;

typedef struct s_philoinfo
{
	int				number_of_philos;
	long			time_to_die;
	long			time_to_eat;
	long			time_to_sleep;
	long			n_time_should_eat;
	int				finished;
	bool			is_die;
	size_t			start_time;
	int				all_ate;
	t_philo			*philo;
	pthread_mutex_t	*forks;
	pthread_mutex_t	print_m;
	pthread_mutex_t	is_die_m;
	pthread_mutex_t	should_die_m;
	pthread_mutex_t	finished_m;
	pthread_mutex_t	last_meal_m;
	pthread_mutex_t	sleep_m;
	pthread_mutex_t	all_ate_m;
}t_philoinfo;

//-----------------------check/create/init_things----------------------//
void			__init_args(t_philoinfo *ph, char **av, int ac);
void			init_all_philos(t_philoinfo *info, int i);
void			__creat_mutex(t_philoinfo *ph);
void			__create_threads_and_philos(t_philoinfo *info);
int				check_death_status(t_philo *each_philo);
int				check_finished_status(t_philo *each_philo);
int				check_death_and_hunger_status(t_philo *each_philo);
size_t			check_last_meal_status(t_philo *each_philo);
void			*__check_death_and_hunger(void *arg);
//----------------------------utils_functions--------------------------//
int				__strlen(const char *str);
void			*__calloc(size_t count, size_t size);
int				ft_atoi(const char *str);
int				cmp(const char *s1, const char *s2);
void			my_own_sleep(t_philo *philo, long time);
long			get_msec_time(void);
// void			*__is_died(void *philo);
long			get_msec_time(void);
//---------------------------routine_and_print--------------------------//
void			*ft_routine(void *philos);
void			eating(t_philo *each_philo);
void			sleep_time(t_philo *philo);
void			__error(int index);
int				__check_info(t_philoinfo info, int ac);
void			mutex_print(t_philo *philo, char *message);

#endif