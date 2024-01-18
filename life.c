/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvisca <mvisca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 17:22:25 by mvisca            #+#    #+#             */
/*   Updated: 2024/01/18 17:31:30 by mvisca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

static void	wait_others(t_table *table)
{
	while (!pthread_mutex_lock(&table->time) && !table->time_zero)
	{
		pthread_mutex_unlock(&table->time);
		ft_usleep(50);
	}
	pthread_mutex_unlock(&table->time);
}

static void	start_life(t_philo *philo)
{
	pthread_mutex_lock(&philo->table->time);
	philo->last_meal = philo->table->time_zero;
	pthread_mutex_unlock(&philo->table->time);
}

// static void	lonely_life(t_philo *philo)
// {
// 	print_fork(philo);
// 	ft_usleep(philo->table->time_die);
// 	print_die(philo);
// }

static void	start_eating(t_philo *philo, t_table *table, t_bool *run)
{
	while (check_philo(philo))
	{
		eat(philo); // actualiza t->philos_done si is_satisfied(philo) retorna true_e
		ft_sleep(philo);
		think(philo);
	}
	while (*run || philo->table->philos_done <= philo->table->philos_n)
		ft_usleep(50);
}

void	*philo_life(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	wait_others(philo->table);
	start_life(philo);
	// if (&philo->left_f == philo->right_f)
	// 	lonely_life(philo);
	// else
	start_eating(philo, philo->table, &philo->table->run);
}
