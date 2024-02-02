/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvisca-g <mvisca-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 17:22:59 by mvisca            #+#    #+#             */
/*   Updated: 2024/02/02 19:59:53 by mvisca-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

long long	get_time(t_table *t)
{
	return (time_now() - getlong(t, START, 0));
}

long long	time_now(void)
{
	struct timeval	time;
	long long		total_time;

	if (gettimeofday(&time, NULL) != 0)
		printf("Error while reading time\n");
	total_time = (time.tv_sec * 1000) + (time.tv_usec / 1000);
	return (total_time);
}

int	ft_sleep(int hold, t_table *t)
{
	long long	starting_time;

	starting_time = time_now();
	while (getint(t, COUNT_DEAD, 0) == 0)
	{
		if (getlong(t, NOW, 0) - starting_time >= hold)
			break ;
		usleep(100);
	}
	return (0);
}

int	ft_atoi(char *str)
{
	long long	result;
	int			i;

	result = 0;
	i = 0;
	while (str && ((str[i] >= 9 && str[i] <= 13) || str[i] == 32))
		i++;
	while (str && str[i])
	{
		result = (result * 10) + str[i] - '0';
		i++;
	}
	if (result < INT_MIN || result > INT_MAX)
		return (-1);
	return (result);
}

int	free_all(t_table *table)
{
	int	n;

	n = 0;
	while (table->philos && n < getint(table, COUNT_CHAIRS, 0))
		pthread_mutex_destroy(&table->philos[n++].fork_l);
	pthread_mutex_destroy(&table->mtx_chairs);
	pthread_mutex_destroy(&table->mtx_dead);
	pthread_mutex_destroy(&table->mtx_hungry);
	pthread_mutex_destroy(&table->mtx_end);
	pthread_mutex_destroy(&table->mtx_philo_meal);
	pthread_mutex_destroy(&table->mtx_die);
	pthread_mutex_destroy(&table->mtx_eat);
	pthread_mutex_destroy(&table->mtx_sleep);
	pthread_mutex_destroy(&table->mtx_meals);
	pthread_mutex_destroy(&table->mtx_now);
	pthread_mutex_destroy(&table->mtx_start);
	pthread_mutex_destroy(&table->mtx_print);
	free(table->philos);
	return (0);
}
