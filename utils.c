/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvisca <mvisca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 17:22:59 by mvisca            #+#    #+#             */
/*   Updated: 2024/01/23 20:33:37 by mvisca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

long long	time_now(void)
{
	struct timeval	time;
	long long		total_time;

	if (gettimeofday(&time, NULL) != 0)
		printf("Error while reading time\n");
	total_time = (time.tv_sec * 1000) + (time.tv_usec / 1000);
	return (total_time);
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
	return ((int) result);
}

int	ft_usleep(int hold, t_table *t)
{
	long long	starting_time;
	int			dead;

	starting_time = time_now();
	while (time_now() - starting_time < hold)
	{
		usleep(10);
		pthread_mutex_lock(&t->mtx_run);
		dead = t->dead_count;
		pthread_mutex_unlock(&t->mtx_run);
		if (dead)
			break ;
	}
	return (1);
}

int	free_all(t_table *table)
{
	int	n;

	pthread_mutex_destroy(&table->mtx_run);
	pthread_mutex_destroy(&table->mtx_print);
	n = 0;
	while (n < table->philos_n)
		pthread_mutex_destroy(&table->philos[n++].fork_l);
	free(table->philos);
	return (0);
}
