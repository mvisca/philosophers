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

// type for bools
typedef enum e_bool
{
	false_e,
	true_e
} t_bool;

struct s_philo;

typedef struct s_table
{
	int				philos_n;
	struct s_philo	*philos;
	long long		time_zero;
	int				time_die;
	int				time_eat;
	int				time_sleep;
	int				total_meals;
	pthread_mutex_t	print;
	pthread_mutex_t	stop_run;
	t_bool			run;
} t_table;

typedef struct s_philo
{
	pthread_t		p_thread;
	int				chair_num;
	long long		last_meal;
	int				meals_count;
	t_bool			is_satisfied;
	t_bool			is_alive;				
	pthread_mutex_t	left_f;
	pthread_mutex_t	*right_f;
	t_table			*table;
} t_philo;

// init.c
t_bool		init_table(int ac, char **av, t_table *table);
t_bool		init_philos(t_table *table);

// error.c
t_bool		print_argserror(void); // in file
t_bool		print_charerror(void); // in file
t_bool		print_mallocerror(t_table *table); // in filie
t_bool		print_mutexinierror(t_table *table); // in file
t_bool		print_maxerror(void); // in file

// validate.c
t_bool		validate_args(int ac, char **av);
t_bool		validate_chars(char **str);

// life.c
t_bool		is_satisfied(t_philo *philo);
t_bool		is_alive(t_philo *philo);
void		eat(t_philo *philo);
void		*philo_life(void *arg);

// print.c
t_bool		print_fork(t_philo *philo);
t_bool		print_eat(t_philo *philo);
t_bool		print_sleep(t_philo *philo);
t_bool		print_think(t_philo *philo);
t_bool		print_die(t_philo *philo);

// join.c
t_bool		join_philos(t_table *table);

// utils.c
long long	time_now(void);
int			ft_atoi(char *str);
t_bool		ft_usleep(int hold);
t_bool		free_all(t_table *table);

void		print_structs(t_table *table);

#endif
