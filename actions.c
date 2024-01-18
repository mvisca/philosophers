/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvisca <mvisca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 20:35:12 by mvisca            #+#    #+#             */
/*   Updated: 2024/01/18 14:28:11 by mvisca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	lonely_life(t_philo *philo)
{
	print_fork(philo);
	ft_usleep(philo->table->time_die);
	print_die(philo);
}

void	fork(t_philo *philo)
{
	if (check_philo(philo))
	{
		if (philo->chair_num % 2 == 0)
		{
			pthread_mutex_lock(philo->right_f);
			print_fork(philo);
			pthread_mutex_unlock(&philo->left_f);
		}
		else if (&philo->left_f == philo->right_f)
			lonely_life(philo);
		else
		{
			pthread_mutex_lock(&philo->left_f);
			print_fork(philo);
			pthread_mutex_lock(philo->right_f);
		}
		print_fork(philo);
	}
}

void	eat(t_philo *philo)
{
	philo->last_meal = time_now();
	ft_usleep(philo->table->time_eat);
	pthread_mutex_unlock(&philo->left_f);
	pthread_mutex_unlock(philo->right_f);
	print_eat(philo);
	philo->meals_count++;
}
