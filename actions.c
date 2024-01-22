/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvisca <mvisca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 20:35:12 by mvisca            #+#    #+#             */
/*   Updated: 2024/01/22 21:04:22 by mvisca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	forks(t_philo *philo)
{
	pthread_mutex_t	*first;
	pthread_mutex_t	*second;

	if (&philo->left_f == philo->right_f)
	{
		print_fork(philo);
		ft_usleep(philo->table->time_die);
		print_die(philo);
		philo->table->run = false_e;
		return ;
	}
	first = &philo->left_f;
	second = philo->right_f;
	if (philo->chair_num % 2 == 0)
	{
		first = philo->right_f;
		second = &philo->left_f;
	}
	pthread_mutex_lock(first);
	print_fork(philo);
	pthread_mutex_lock(second);
	print_fork(philo);
}

void	eat(t_philo *philo)
{
	if (!check_philo(philo))
		return ;
	philo->last_meal = time_now();
	ft_usleep(philo->table->time_eat);
	pthread_mutex_unlock(&philo->left_f);
	pthread_mutex_unlock(philo->right_f);
	print_eat(philo);
	philo->meals_count++;
	printf("*** Philo %d meals = %d\n", philo->chair_num, philo->meals_count);
	pthread_mutex_lock(&philo->table->count);
	if (philo->meals_count == philo->table->total_meals)
		philo->table->philos_done++;
	pthread_mutex_unlock(&philo->table->count);
}

void	ft_sleep(t_philo *philo)
{
	printf("Sleep %d\n", philo->chair_num);

	if (check_philo(philo))
	{
		print_sleep(philo);
		ft_usleep(philo->table->time_sleep);
	}
}

void	think(t_philo *philo)
{
	printf("Think %d\n", philo->chair_num);

	if (check_philo(philo))
	{
		print_think(philo);
	}
}
