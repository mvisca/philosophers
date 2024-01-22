/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvisca <mvisca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 17:22:54 by mvisca            #+#    #+#             */
/*   Updated: 2024/01/22 21:17:38 by mvisca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_bool	print_fork(t_philo *philo)
{
	long long	time;
	t_bool		local_run;

	pthread_mutex_lock(&philo->table->print);

	pthread_mutex_lock(&philo->table->stop_run);
	local_run = philo->table->run;
	pthread_mutex_unslock(&philo->table->stop_run);

	if (local_run && philo->table->philos_done < philo->table->philos_n)
	{
		pthread_mutex_lock(&philo->table->count);
		time = ustoms(time_now(), philo->table->time_zero);
		pthread_mutex_unlock(&philo->table->count);
		printf("%lld\t%d\thas taken a fork\n", time, philo->chair_num);
	}	
	pthread_mutex_unlock(&philo->table->print);
	return (true_e);
}

t_bool	print_eat(t_philo *philo)
{
	long long	time;

	time = ustoms(philo->last_meal, philo->table->time_zero);
	pthread_mutex_lock(&philo->table->stop_run);
	if (philo->table->run)
	{
		pthread_mutex_lock(&philo->table->count);
		if (philo->table->philos_done != philo->table->philos_n)
		{
			pthread_mutex_lock(&philo->table->print);
			printf("%lld\t%d\tis eating\n", time, philo->chair_num);
			pthread_mutex_unlock(&philo->table->print);
		}
		pthread_mutex_unlock(&philo->table->count);
	}	
	pthread_mutex_unlock(&philo->table->stop_run);
	return (true_e);
}

t_bool	print_sleep(t_philo *philo)
{
	long long	time;

	time = ustoms(time_now(), philo->table->time_zero);
	pthread_mutex_lock(&philo->table->stop_run);
	if (philo->table->run)
	{
		pthread_mutex_lock(&philo->table->count);
		if (philo->table->philos_done != philo->table->philos_n)
		{
			pthread_mutex_lock(&philo->table->print);
			printf("%lld\t%d \tis sleeping\n", time, philo->chair_num);
			pthread_mutex_unlock(&philo->table->print);
		}
		pthread_mutex_unlock(&philo->table->count);
	}	
	pthread_mutex_unlock(&philo->table->stop_run);
	return (true_e);
}

t_bool	print_think(t_philo *philo)
{
	long long	time;

	time = ustoms(time_now(), philo->table->time_zero);
	pthread_mutex_lock(&philo->table->stop_run);
	if (philo->table->run)
	{
		pthread_mutex_lock(&philo->table->count);
		if (philo->table->philos_done != philo->table->philos_n)
		{
			pthread_mutex_lock(&philo->table->print);
			printf("%lld\t%d\tis thinking\n", time, philo->chair_num);
			pthread_mutex_unlock(&philo->table->print);
		}
		pthread_mutex_unlock(&philo->table->count);
	}	
	pthread_mutex_unlock(&philo->table->stop_run);
	return (true_e);
}

t_bool	print_die(t_philo *philo)
{
	long long	time;

	time = ustoms(time_now(), philo->table->time_zero);
	pthread_mutex_lock(&philo->table->stop_run);
	pthread_mutex_lock(&philo->table->count);
	if (philo->table->philos_done != philo->table->philos_n)
	{
		pthread_mutex_lock(&philo->table->print);
		printf("%lld\t%d\tdied\n", time, philo->chair_num);
		pthread_mutex_unlock(&philo->table->print);
	}
	pthread_mutex_unlock(&philo->table->count);
	pthread_mutex_unlock(&philo->table->stop_run);
	return (true_e);
}
