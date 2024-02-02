/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_time.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvisca-g <mvisca-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 16:54:17 by mvisca            #+#    #+#             */
/*   Updated: 2024/02/02 16:04:36 by mvisca-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	update_last_meal(t_philo *philo)
{
	pthread_mutex_lock(&philo->t->mtx_philo_meal);
	philo->last_meal = getlong(philo->t, NOW, 0);
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
