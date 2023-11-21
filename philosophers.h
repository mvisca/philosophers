/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvisca-g <mvisca-g@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 18:01:02 by mvisca-g          #+#    #+#             */
/*   Updated: 2023/11/21 19:04:26 by mvisca-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <limits.h>
# include <pthread.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>

typedef struct s_philo
{
	pthread_t			*philo_thread;
	int					philo_index;
	int					is_alive;
	int					is_done; 
	uint64_t			last_meal;
} t_philo;

typedef struct s_gym
{	
	t_philo				**philos;
	pthread_mutex_t 	*forks;
	pthread_mutex_t		*printing;
	int					total_philos;
	uint64_t			open_time;
	uint64_t			time_to_die; 
	uint64_t			time_to_eat;
	uint64_t			time_to_sleep;
	int					meals_to_be_done;
} t_gym;
// ttd > tte + tts
// total_philos % 2 ? ttd > tte * 2 : ttd > tte * 3

typedef enum e_integers
{
	c,
	i,
	j,
	k,
	x,
	y,
	fd,
	end,
	len,
	max,
	min,
	num,
	sum,
	len1,
	len2,
	byte,
	chars,
	count,
	size,
	octet,
	start,
	total,
	words,
	digits,
	bytes_read,
	integers_array_len
} t_integers;

// utils
void		error_exit(char *str, int exit_code);
int			clean_tab(char **tab);
uint64_t	ft_ato64(char *ascii);
int			ft_atoi(char *ascii);
int			arr_len(char **tab);

// creator
int			gym_forks_create(t_gym *gym);
int			gym_philos_create(t_gym *gym);

// parse
int			gym_init(t_gym *gym, int ac, char **av);
int			command_args_error(void);

// open
int			gym_open(t_gym *gym);	
int			gym_thread_create(t_gym *gym);
int			gym_thread_destroy(t_gym *gym);
void		*gym_table(void *data);

// time
uint64_t	gym_gettime(void);

// debug
void		debug_struct(t_gym *gym);
void		debug_print_time(void);

#endif
