/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_time.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvisca <mvisca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 16:54:17 by mvisca            #+#    #+#             */
/*   Updated: 2024/01/24 18:30:05 by mvisca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long	get_time(t_table *t)
{
	long long	time;

	pthread_mutex_lock(&t->mtx_time);
	time = time_now() - t->start_time;
	pthread_mutex_unlock(&t->mtx_time);
	return (time);
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

int	ft_usleep(int hold, t_table *t)
{
	long long	starting_time;
	int			dead;

	starting_time = time_now();
	while (time_now() - starting_time < hold)
	{
		pthread_mutex_lock(&t->mtx_dead);
		dead = t->dead_count;
		pthread_mutex_unlock(&t->mtx_dead);
		if (dead != 0)
			break ;
		usleep(10);
	}
	return (0);
}
