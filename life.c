/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvisca <mvisca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 17:22:25 by mvisca            #+#    #+#             */
/*   Updated: 2024/01/09 18:52:22 by mvisca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

t_bool	is_satisfied(t_philo *philo)
{
	if (philo->meals_count == philo->table->total_meals)
	{
		pthread_mutex_lock(&philo->table->count);
		philo->table->philos_done++;
		pthread_mutex_unlock(&philo->table->count);
		return (true_e);
	}
	return (false_e);
}

t_bool	is_alive(t_philo *philo)
{
	if (time_now() - philo->last_meal < philo->table->time_die)
		return (true_e);
	stop_tablerun(philo->table);
	print_die(philo);
	return (false_e);
}

void	eat(t_philo *philo)
{
	if (is_alive(philo))
	{
		if (philo->chair_num % 2 == 0)
		{
			ft_usleep(20);
			pthread_mutex_lock(philo->right_f);
			print_fork(philo);
			pthread_mutex_lock(&philo->left_f);
			print_fork(philo);
		}
		else
		{
			pthread_mutex_lock(&philo->left_f);
			print_fork(philo);
			pthread_mutex_lock(philo->right_f);
			print_fork(philo);
		}	
		philo->last_meal = time_now();
		pthread_mutex_unlock(&philo->left_f);
		pthread_mutex_unlock(philo->right_f);
		print_eat(philo);
		philo->meals_count++;
	}
}

void	stop_tablerun(t_table *table)
{
	pthread_mutex_lock(&table->stop_run);
	table->run = false_e;
	pthread_mutex_unlock(&table->stop_run);
}

void	*philo_life(void *arg)
{
	t_philo	*philo;
	t_table	*t;
	t_bool	*run;

	philo = (t_philo *)arg;
	t = philo->table;
	run = &t->run;
	while (!t->time_zero)
		usleep(20);
	philo->last_meal = t->time_zero;
	while (*run && is_alive(philo) && !is_satisfied(philo) \
		&& t->philos_done != t->total_meals)
	{
		eat(philo);
		if (*run && is_alive(philo) && !is_satisfied(philo) && print_sleep(philo))
			ft_usleep(philo->table->time_sleep);
		if (*run && is_alive(philo) && !is_satisfied(philo))
			print_think(philo);
	}
	while (*run && philo->table->philos_done <= philo->table->philos_n)
		ft_usleep(100);
	return (NULL);
}
