/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvisca <mvisca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 17:22:49 by mvisca            #+#    #+#             */
/*   Updated: 2024/01/23 02:36:59 by mvisca           ###   ########.fr       */
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

// custom type for bools
typedef enum e_bool
{
	false_e,
	true_e
}	t_bool;

// custom type to protect mutex @ init_table()  
typedef struct s_ints
{
	int				alive;
	int				meals;
	int				print;
	int				satisfied;
	int				time;
}	t_ints;

// prototype to nest s_philo in s_table
struct	s_philo;

typedef struct s_table
{
	int				philos_n;
	int				die_time;
	int				eat_time;
	int				sleep_time;
	int				meals_target;
	long long		time_zero;
	t_bool			alive_all;
	t_bool			hungry_count;
	pthread_mutex_t	use_alive;
	pthread_mutex_t	use_meals;
	pthread_mutex_t	use_print;
	pthread_mutex_t	use_hungry;
	pthread_mutex_t	use_time;
	struct s_philo	*philos;
}	t_table;

typedef struct s_philo
{
	pthread_t		philo_thread;
	int				philo_n;
	int				meals_due;
	long long		meal_last;
	t_bool			alive_me;
	t_bool			hungry_me;
	pthread_mutex_t	fork_l;
	pthread_mutex_t	*fork_r;
	t_table			*t;
}	t_philo;

// // custom type to reduce code @ philo_life()
// typedef struct s_custom
// {
// 	t_philo			*philo;
// 	t_table			*table;
// }	t_custom;

// validate.c
t_bool		validate_args(int ac, char **av);
t_bool		validate_chars(char **str);
t_bool		is_alive(t_philo *philo);
t_bool		is_hungry(t_philo *philo);
t_bool		check_philo(t_philo *philo);

// init.c
t_bool		init_table(int ac, char **av, t_table *table);
t_bool		init_philos(t_table *table);

// life.c
void		*philo_life(void *arg);

// actions.c
void		philo_fork(t_philo *philo);
void		philo_eat(t_philo *philo);
void		philo_sleep(t_philo *philo);
void		philo_think(t_philo *philo);

// join.c
void		philo_alone(t_philo *philo);
t_bool		join_philos(t_table *table);

// error.c
t_bool		print_argserror(void); // in file
t_bool		print_charerror(void); // in file
t_bool		print_mallocerror(t_table *table); // in filie
t_bool		print_mutexinierror(t_table *table); // in file
t_bool		print_maxerror(void); // in file

// print.c
t_bool		print_fork(t_philo *philo);
t_bool		print_eat(t_philo *philo);
t_bool		print_sleep(t_philo *philo);
t_bool		print_think(t_philo *philo);
t_bool		print_die(t_philo *philo);

// utils.c
long long	time_now(void);
long long	ustoms(long long t, long long t_z);
int			ft_atoi(char *str);
t_bool		ft_usleep(int hold);
t_bool		free_all(t_table *table);


#endif
