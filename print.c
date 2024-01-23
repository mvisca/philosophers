/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvisca <mvisca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 17:22:54 by mvisca            #+#    #+#             */
/*   Updated: 2024/01/23 01:26:52 by mvisca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_bool	print_fork(t_philo *philo)
{
	long long	time;

	pthread_mutex_lock(&philo->t->use_time);
	time = ustoms(time_now(), philo->t->time_zero);
	pthread_mutex_unlock(&philo->t->use_time);
	if (check_philo(philo))
	{
		pthread_mutex_lock(&philo->t->use_print);
		printf("%lld\t%d\thas taken a fork\n", time, philo->philo_n);
		pthread_mutex_unlock(&philo->t->use_print);
	}
	return (true_e);
}

t_bool	print_eat(t_philo *philo)
{
	long long	time;

	pthread_mutex_lock(&philo->t->use_time);
	time = ustoms(philo->meal_last, philo->t->time_zero);
	pthread_mutex_unlock(&philo->t->use_time);
	if (check_philo(philo))
	{
		pthread_mutex_lock(&philo->t->use_print);
		printf("%lld\t%d\tis eating\n", time, philo->philo_n);
		pthread_mutex_unlock(&philo->t->use_print);	
	}	
	return (true_e);
}

t_bool	print_sleep(t_philo *philo)
{
	long long	time;

	pthread_mutex_lock(&philo->t->use_time);
	time = ustoms(time_now(), philo->t->time_zero);
	pthread_mutex_unlock(&philo->t->use_time);
	if (check_philo(philo))
	{
		pthread_mutex_lock(&philo->t->use_print);
		printf("%lld\t%d \tis sleeping\n", time, philo->philo_n);
		pthread_mutex_unlock(&philo->t->use_print);
	}	
	return (true_e);
}

t_bool	print_think(t_philo *philo)
{
	long long	time;

	pthread_mutex_lock(&philo->t->use_time);
	time = ustoms(time_now(), philo->t->time_zero);
	pthread_mutex_lock(&philo->t->use_time);

	if (check_philo(philo))
	{
		pthread_mutex_lock(&philo->t->use_print);
		printf("%lld\t%d\tis thinking\n", time, philo->philo_n);
		pthread_mutex_unlock(&philo->t->use_print);
	}
	return (true_e);
}

t_bool	print_die(t_philo *philo)
{
	long long	time;

	pthread_mutex_lock(&philo->t->use_time);
	time = ustoms(time_now(), philo->t->time_zero);
	pthread_mutex_unlock(&philo->t->use_time);
	pthread_mutex_lock(&philo->t->use_print);
	printf("%lld\t%d\tdied\n", time, philo->philo_n);
	pthread_mutex_unlock(&philo->t->use_print);
	return (true_e);
}
