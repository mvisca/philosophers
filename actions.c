/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvisca <mvisca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 20:35:12 by mvisca            #+#    #+#             */
/*   Updated: 2024/01/23 02:49:11 by mvisca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_fork(t_philo *philo)
{
	pthread_mutex_t	*first;
	pthread_mutex_t	*second;

	first = &philo->fork_l;
	second = philo->fork_r;
	if (philo->philo_n % 2 == 0)
	{
		first = philo->fork_r;
		second = &philo->fork_l;
		ft_usleep(50);
	}
	pthread_mutex_lock(first);
	print_fork(philo);
	pthread_mutex_lock(second);
	print_fork(philo);
}

void	philo_eat(t_philo *philo)
{
	if (!check_philo(philo))
		return ;
	philo->meal_last = time_now();
	pthread_mutex_lock(&philo->t->use_time);
	ft_usleep(philo->t->eat_time);
	pthread_mutex_unlock(&philo->t->use_time);
	pthread_mutex_unlock(&philo->fork_l);
	pthread_mutex_unlock(philo->fork_r);
	print_eat(philo);
	philo->meals_due--;
}

void	philo_sleep(t_philo *philo)
{
	if (!check_philo(philo))
		return ;
	print_sleep(philo);
	pthread_mutex_lock(&philo->t->use_time);
	ft_usleep(philo->t->sleep_time);	
	pthread_mutex_unlock(&philo->t->use_time);
}

void	philo_think(t_philo *philo)
{
	if (!check_philo(philo))
		return ;
	print_think(philo);
}
