/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvisca <mvisca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 20:35:12 by mvisca            #+#    #+#             */
/*   Updated: 2024/01/18 17:30:35 by mvisca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	get_forks(t_philo *philo, t_philo_case philo_case)
{
	if (philo_case == alone)
	{
		print_fork(philo);
		ft_usleep(philo->table->time_die);
		print_die(philo);
		return ;
	}
	else if (philo_case == even)
	{
		ft_usleep(50);
		pthread_mutex_lock(philo->right_f);
		print_fork(philo);
		pthread_mutex_lock(&philo->left_f);
	}
	else if (philo_case == odd)
	{
		pthread_mutex_lock(&philo->left_f);
		print_fork(philo);
		pthread_mutex_lock(philo->right_f);
	}
	else
		printf("Invalid call of 'use_forks()'\n");
	print_fork(philo);
}

void	eat(t_philo *philo)
{
	if (check_philo(philo))
	{
		if (philo->chair_num % 2 == 0)
			get_forks(philo, even);
		else if (&philo->left_f == philo->right_f)
			get_forks(philo, alone);
		else
			get_forks(philo, odd);
	}
	if (check_philo(philo))
	{
		philo->last_meal = time_now();
		ft_usleep(philo->table->time_eat);
		pthread_mutex_unlock(&philo->left_f);
		pthread_mutex_unlock(philo->right_f);
		print_eat(philo);
		philo->meals_count++;
	}
	if (philo->meals_count == philo->table->total_meals)
	{
		pthread_mutex_lock(&philo->table->count);
		philo->table->philos_done++;
		pthread_mutex_unlock(&philo->table->count);
	}
}

void	ft_sleep(t_philo *philo)
{
	if (check_philo(philo))
	{
		print_sleep(philo);
		ft_usleep(philo->table->time_sleep);
	}
}

void	think(t_philo *philo)
{
	if (check_philo(philo))
	{
		print_think(philo);
	}
}
