/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvisca <mvisca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 17:22:25 by mvisca            #+#    #+#             */
/*   Updated: 2024/01/24 12:41:09 by mvisca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

static void	wait_others(t_table *t)
{
	long long	time;

	while (1)
	{
//		pthread_mutex_lock(&t->mtx_run);
		time = t->start_time;
//		pthread_mutex_unlock(&t->mtx_run);
		if (time != 0)
			break ;
		ft_usleep(20, t);
	}
}

static void	life_cycle(t_philo *philo)
{
	int	stop;

	stop = 0;
	while (!stop && !philo->t->dead_count)
	{
		stop = philo_eat(philo);
		if (!stop && !philo->t->dead_count)
		{
			print_sleep(philo);
			ft_usleep(philo->t->sleep_time, philo->t);
		}
		if (!stop && !philo->t->dead_count)
			print_think(philo);
	}
}

void	*philo_life(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	wait_others(philo->t);
	pthread_mutex_lock(&philo->t->mtx_run);
	philo->last_meal = philo->t->start_time;
	pthread_mutex_unlock(&philo->t->mtx_run);
	life_cycle(philo);
	return (NULL);
}
