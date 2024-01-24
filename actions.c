/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvisca <mvisca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 20:35:12 by mvisca            #+#    #+#             */
/*   Updated: 2024/01/24 17:27:55 by mvisca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	take_forks(t_philo *philo)
{
	if (philo->chair % 2)
	{
		ft_usleep(40, philo->t);
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
	philo->last_meal = time_now();
	print_eat(philo);
	ft_usleep(get_safe(philo->t, EAT), philo->t);
	philo->meals_count += 1;
	pthread_mutex_unlock(&philo->fork_l);
	pthread_mutex_unlock(philo->fork_r);
	if (philo->meals_count >= philo->t->max_meals)
	{
		pthread_mutex_lock(&philo->t->mtx_hungry);
		philo->t->hungry_count -= 1;
		pthread_mutex_unlock(&philo->t->mtx_hungry);
		return (1);
	}
	return (0);
}
