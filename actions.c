/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvisca <mvisca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 20:35:12 by mvisca            #+#    #+#             */
/*   Updated: 2024/01/23 20:33:00 by mvisca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	take_forks(t_philo *philo)
{
	if (philo->chair % 2)
	{
		pthread_mutex_lock(&philo->fork_l);
		print_fork(philo);
		if (&philo->fork_l == philo->fork_r)
			return (1);
		pthread_mutex_lock(philo->fork_r);
		print_fork(philo);
		return (0);
	}
	else
	{
		pthread_mutex_lock(philo->fork_r);
		print_fork(philo);
		pthread_mutex_lock(&philo->fork_l);
		print_fork(philo);
	}
	return (0);
}

int	philo_eat(t_philo *philo)
{
	if (take_forks(philo))
		return (1);
	pthread_mutex_lock(&philo->t->mtx_run);
	philo->last_meal = time_now();
	print_eat(philo);
	pthread_mutex_unlock(&philo->t->mtx_run);
	ft_usleep(philo->t->eat_time, philo->t);
	philo->meals_count += 1;
	pthread_mutex_unlock(&philo->fork_l);
	pthread_mutex_unlock(philo->fork_r);
	if (philo->meals_count >= philo->t->max_meals)
	{
		pthread_mutex_lock(&philo->t->mtx_run);
		philo->t->hungry_count -= 1;
		pthread_mutex_unlock(&philo->t->mtx_run);
		return (1);
	}
	return (0);
}
