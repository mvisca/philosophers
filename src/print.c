/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvisca-g <mvisca-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 17:22:54 by mvisca            #+#    #+#             */
/*   Updated: 2024/02/02 19:20:38 by mvisca-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	print_fork(t_philo *philo)
{
	pthread_mutex_lock(&philo->t->mtx_print);
	if (pt_dead(philo->t))
	{
		pthread_mutex_unlock(&philo->t->mtx_print);
		return (1);
	}
	printf("%lld\t%d\thas taken a fork\n", get_time(philo->t), philo->chair);
	pthread_mutex_unlock(&philo->t->mtx_print);
	return (0);
}

int	print_eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->t->mtx_print);
	if (pt_dead(philo->t))
	{
		pthread_mutex_unlock(&philo->t->mtx_print);
		return (1);
	}
	printf("%lld\t%d\tis eating\n", get_time(philo->t), philo->chair);
	pthread_mutex_unlock(&philo->t->mtx_print);
	return (1);
}

int	print_sleep(t_philo *philo)
{
	pthread_mutex_lock(&philo->t->mtx_print);
	if (pt_dead(philo->t))
	{
		pthread_mutex_unlock(&philo->t->mtx_print);
		return (1);
	}
	printf("%lld\t%d \tis sleeping\n", get_time(philo->t), philo->chair);
	pthread_mutex_unlock(&philo->t->mtx_print);
	return (1);
}

int	print_think(t_philo *philo)
{
	pthread_mutex_lock(&philo->t->mtx_print);
	if (pt_dead(philo->t))
	{
		pthread_mutex_unlock(&philo->t->mtx_print);
		return (1);
	}
	printf("%lld\t%d\tis thinking\n", get_time(philo->t), philo->chair);
	pthread_mutex_unlock(&philo->t->mtx_print);
	return (1);
}

int	print_die(t_philo *philo)
{
	pthread_mutex_lock(&philo->t->mtx_print);
	printf("%lld\t%d\tdied\n", get_time(philo->t), philo->chair);
	pthread_mutex_unlock(&philo->t->mtx_print);
	return (0);
}
