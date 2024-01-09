/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvisca <mvisca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 17:22:54 by mvisca            #+#    #+#             */
/*   Updated: 2024/01/09 17:22:55 by mvisca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_bool	print_fork(t_philo *philo)
{
	pthread_mutex_lock(&philo->table->print);
	printf("%lld %d has taken a fork\n", time_now(), philo->chair_num);
	pthread_mutex_unlock(&philo->table->print);
	return (true_e);
}

t_bool	print_eat(t_philo *philo)
{	
	pthread_mutex_lock(&philo->table->print);
	printf("%lld %d is eating\n", philo->last_meal, philo->chair_num);
	pthread_mutex_unlock(&philo->table->print);
	return (true_e);
}

t_bool	print_sleep(t_philo *philo)
{
	pthread_mutex_lock(&philo->table->print);
	printf("%lld %d is sleeping\n", time_now(), philo->chair_num);
	pthread_mutex_unlock(&philo->table->print);
	return (true_e);
}

t_bool	print_think(t_philo *philo)
{
	pthread_mutex_lock(&philo->table->print);
	printf("%lld %d is thinking\n", time_now(), philo->chair_num);
	pthread_mutex_unlock(&philo->table->print);
	return (true_e);
}

t_bool	print_die(t_philo *philo)
{
	pthread_mutex_lock(&philo->table->print);
	printf("%lld %d died\n", time_now(), philo->chair_num);
	pthread_mutex_unlock(&philo->table->print);
	return (true_e);
}
