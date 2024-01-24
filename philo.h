/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvisca <mvisca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 17:22:49 by mvisca            #+#    #+#             */
/*   Updated: 2024/01/24 18:34:06 by mvisca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

// memset
# include <string.h>

// printf
# include <stdio.h>

// malloc free
# include <stdlib.h>

// usleep write
# include <unistd.h>

// gettimeofday
# include <sys/time.h>

// pthread_create/detach/join
//phtread_mutex_init/destroy/lock/unlock
# include <pthread.h>

// use bool type
# include <stdbool.h>

// use for typeoverflow control
# include <limits.h>

# define DEAD	0
# define DIE	1
# define EAT	2
# define HUNGRY	3
# define SLEEP	4
# define START	5

// custom type to protect mutex @ init_table()  
typedef struct s_ints
{
	int				dead;
	int				print;
	int				time;
	int				hungry;
}	t_ints;

// prototype to nest s_philo in s_table
struct	s_philo;

typedef struct s_table
{
	int				philos_n;
	int				die_time;
	int				eat_time;
	int				sleep_time;
	int				max_meals;
	long long		start_time;
	int				dead_count;
	int				hungry_count;
	pthread_mutex_t	mtx_print;
	pthread_mutex_t	mtx_dead;
	pthread_mutex_t	mtx_time;
	pthread_mutex_t	mtx_hungry;
	struct s_philo	*philos;
}	t_table;

typedef struct s_philo
{
	pthread_t		philo_thread;
	int				chair;
	int				meals_count;
	long long		last_meal;
	pthread_mutex_t	fork_l;
	pthread_mutex_t	*fork_r;
	t_table			*t;
}	t_philo;

// validate.c
int					validate_args(int ac, char **av);
int					validate_chars(char **str);

// init.c
int					init_table(int ac, char **av, t_table *table);
int					init_philos(t_table *table);

// life.c
int					dead_philo(t_philo *philo);
void				running(t_table *table);
void				*philo_life(void *arg);

// actions.c
int					philo_eat(t_philo *philo);

// error.c
int					print_argserror(void); // in file
int					print_charerror(void); // in file
int					print_mallocerror(t_table *table); // in filie
int					print_mutexinierror(t_table *table); // in file
int					print_maxerror(void); // in file

// print.c
int					print_fork(t_philo *philo);
int					print_eat(t_philo *philo);
int					print_sleep(t_philo *philo);
int					print_think(t_philo *philo);
int					print_die(t_philo *philo);

// utils.c
int					ft_atoi(char *str);
int					free_all(t_table *table);
int					get_safe(t_table *t, int op);

// utils_time.c
long long			get_time(t_table *t);
long long			time_now(void);
int					ft_usleep(int hold, t_table *t);

#endif
