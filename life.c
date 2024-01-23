/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvisca <mvisca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 17:22:25 by mvisca            #+#    #+#             */
/*   Updated: 2024/01/23 02:43:20 by mvisca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

static void	wait_others(t_table *t)
{
	t_bool	loop;

	loop = true_e;
	while (loop)
	{
		ft_usleep(50);
		pthread_mutex_lock(&t->use_time);
		if (t->time_zero != 0)
			loop = false_e;
		pthread_mutex_unlock(&t->use_time);
	}
}

static void	life_cycle(t_philo *philo, t_table *t)
{
	if (&philo->fork_l == philo->fork_r)
		philo_alone(philo);
	while (check_philo(philo) && t->hungry_count)
	{
		philo_fork(philo);
		philo_eat(philo); 
		philo_sleep(philo);
		philo_think(philo);
	}
	while (t->alive_all && t->hungry_count)
	{
		philo->meal_last = time_now();
		check_philo(philo);
	}
}

void	*philo_life(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	wait_others(philo->t);
	pthread_mutex_lock(&philo->t->use_time);
	philo->meal_last = philo->t->time_zero;
	pthread_mutex_unlock(&philo->t->use_time);
	life_cycle(philo, philo->t);
}
