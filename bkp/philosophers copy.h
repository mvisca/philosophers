#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdint.h>
# include <limits.h>

typedef struct s_philo
{
	pthread_t		*philo_thread;
	int				philo_index;
	int				is_alive;
	int				is_done; 
	uint64_t		last_meal;
} t_philo;

typedef struct s_gym
{	
	t_philo				**philos;
	pthread_mutex_t 	**forks;
	pthread_mutex_t		printing;
	int					meals_to_be_done;
	int					total_philos;
	uint64_t			open_time;
	uint64_t			time_to_die; 
	// ttd > tte + tts
	// total_philos % 2 ? ttd > tte * 2 : ttd > tte * 3
	uint64_t			time_to_eat;
	uint64_t			time_to_sleep;
} t_gym;

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

// parse
int			gym_init(t_gym *gym, int ac, char **av);
int			command_args_error(void);

// split (for parseing)
// char		**ft_split(char *str, char c);

//  split utils
// int		ft_isspace(char c);
// int		ft_isalpha(char c);
// int		ft_is_end(char *str, char c, int i);
// int		ft_is_start(char *str, char c, int i);

// debug
void		debug_struct(t_gym *gym);

#endif
