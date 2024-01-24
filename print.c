/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvisca <mvisca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 17:22:54 by mvisca            #+#    #+#             */
/*   Updated: 2024/01/24 12:41:48 by mvisca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	print_fork(t_philo *philo)
{
	long long	time;
	
	time = time_now() - philo->last_meal;
	pthread_mutex_lock(&philo->t->mtx_print);
	printf("%lld\t%d\thas taken a fork\n", time, philo->chair);
	pthread_mutex_unlock(&philo->t->mtx_print);
	return (0);
}

int	print_eat(t_philo *philo)
{
	long long	time;

	time = philo->last_meal - philo->t->start_time;
	pthread_mutex_lock(&philo->t->mtx_print);
	printf("%lld\t%d\tis eating\n", time, philo->chair);
	pthread_mutex_unlock(&philo->t->mtx_print);	
	return (1);
}

int	print_sleep(t_philo *philo)
{
	long long	time;

	time = time_now() - philo->t->start_time;
	pthread_mutex_lock(&philo->t->mtx_print);
	printf("%lld\t%d \tis sleeping\n", time, philo->chair);
	pthread_mutex_unlock(&philo->t->mtx_print);
	return (1);
}

int	print_think(t_philo *philo)
{
	long long	time;

	time = time_now() - philo->t->start_time;
	pthread_mutex_lock(&philo->t->mtx_print);
	printf("%lld\t%d\tis thinking\n", time, philo->chair);
	pthread_mutex_unlock(&philo->t->mtx_print);
	return (1);
}

int	print_die(t_philo *philo)
{
	pthread_mutex_lock(&philo->t->mtx_print);
	if (!philo->t->dead_count)
		printf("%lld\t%d\tdied\n", time_now(), philo->chair);
	pthread_mutex_unlock(&philo->t->mtx_print);
	return (1);
}
