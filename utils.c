/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvisca-g <mvisca-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 17:22:59 by mvisca            #+#    #+#             */
/*   Updated: 2024/01/10 20:21:17 by mvisca-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

long long	time_now(void)
{
	struct timeval	time;
	long long		total_time;

	if (gettimeofday(&time, NULL) != 0)
		printf("Error while reading time\n");
	total_time = (time.tv_sec * 1e6) + time.tv_usec;
	return (total_time);
}

long long	ustoms(long long t, long long t_z)
{
	return ((t - t_z) / 1000);
}

int	ft_atoi(char *str)
{
	long long	result;
	int			i;

	result = 0;
	i = 0;
	while (str && ((str[i] >= 9 && str[i] <= 13) || str[i] == 32))
		i++;
	while (str[i])
	{
		result = (result * 10) + str[i] - '0';
		i++;
	}
	if (result < INT_MIN || result > INT_MAX)
		return (-1);
	return ((int) result);
}

t_bool	ft_usleep(int hold)
{
	long long	starting_time;

	starting_time = time_now();
	while (time_now() - starting_time < hold)
		usleep(50);
	return (true_e);
}

t_bool	free_all(t_table *table)
{
	int	n;

	n = 0;
	while (n < table->philos_n)
	{
		pthread_mutex_destroy(&table->philos[n].left_f);
		n++;
	}
	free(table->philos);
	pthread_mutex_destroy(&table->print);
	pthread_mutex_destroy(&table->stop_run);
	pthread_mutex_destroy(&table->count);
	return (false_e);
}
