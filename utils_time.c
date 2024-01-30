/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_time.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvisca <mvisca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 16:54:17 by mvisca            #+#    #+#             */
/*   Updated: 2024/01/30 16:22:32 by mvisca-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	update_last_meal(t_philo *philo)
{
	long long	now;

	pthread_mutex_lock(&philo->t->mtx_now);
	now = time_now();
	pthread_mutex_unlock(&philo->t->mtx_now);
	pthread_mutex_lock(&philo->t->mtx_philo_meal);
	philo->last_meal = now;
	philo->meals_count = philo->meals_count + 1;
	pthread_mutex_unlock(&philo->t->mtx_philo_meal);
}

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

int	ft_usleep(int hold, t_table *t)
{
	long long	starting_time;

	starting_time = time_now();
	while (getint(t, COUNT_DEAD, 0) == 0)
	{
		if (getlong(t, NOW, 0) - starting_time >= hold)
			break ;
		usleep(1000);
	}
	return (0);
}
