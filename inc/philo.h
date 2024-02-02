/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvisca-g <mvisca-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 17:22:49 by mvisca            #+#    #+#             */
/*   Updated: 2024/02/02 19:19:28 by mvisca-g         ###   ########.fr       */
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

# define COUNT_CHAIRS	0
# define COUNT_DEAD		1
# define COUNT_HUNGRY	2
# define P_LAST_MEAL	3
# define P_MEAL_COUNT	4
# define TIME_DIE		5
# define TIME_EAT		6
# define TIME_SLEEP		7
# define MAX_MEALS		8
# define START			9
# define NOW			10

// custom type to protect mutex @ init_table()  
typedef struct s_ints
{
	int				cch;
	int				cde;
	int				chu;
	int				end;
	int				pm;
	int				tdi;
	int				tea;
	int				tsl;
	int				mxm;
	int				nw;
	int				str;
	int				pr;
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
	pthread_mutex_t	mtx_chairs;
	pthread_mutex_t	mtx_dead;
	pthread_mutex_t	mtx_hungry;
	pthread_mutex_t	mtx_end;
	pthread_mutex_t	mtx_philo_meal;
	pthread_mutex_t	mtx_die;
	pthread_mutex_t	mtx_eat;
	pthread_mutex_t	mtx_sleep;
	pthread_mutex_t	mtx_meals;
	pthread_mutex_t	mtx_now;
	pthread_mutex_t	mtx_start;
	pthread_mutex_t	mtx_print;
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

// main.c
void				running(t_table *table);

// validate.c
int					validate_args(int ac, char **av);
int					validate_chars(char **str);

// init.c
int					init_table(int ac, char **av, t_table *table);
int					init_philos(t_table *table);

// life.c
int					philo_die(t_philo *philo);
void				*philo_life(void *arg);

// print.c
int					print_fork(t_philo *philo);
int					print_eat(t_philo *philo);
int					print_sleep(t_philo *philo);
int					print_think(t_philo *philo);
int					print_die(t_philo *philo);

// error.c
int					print_argserror(void);
int					print_charerror(void);
int					print_mallocerror(void);
int					print_mutexinierror(void);
int					print_maxerror(void);

// getters.c
int					getint(t_table *t, int op, int chair);
long long			getlong(t_table *t, int op, int chair);

// conditions.c
int					p_dead(t_philo *p, t_table *t);
int					p_hungry(t_philo *p, t_table *t);
int					pt_dead(t_table *t);
int					pt_hungry(t_table *t);

// utils.c
int					ft_atoi(char *str);
int					free_all(t_table *table);
int					ft_sleep(int hold, t_table *t);
long long			get_time(t_table *t);
long long			time_now(void);

#endif
