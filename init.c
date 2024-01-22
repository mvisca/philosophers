/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvisca <mvisca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 17:21:51 by mvisca            #+#    #+#             */
/*   Updated: 2024/01/22 22:12:10 by mvisca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_bool	init_table(int ac, char **av, t_table *table)
{
	t_ints	i;

	table->philos_n = ft_atoi(av[1]);
	table->die_time = ft_atoi(av[2]) * 1000;
	table->eat_time = ft_atoi(av[3]) * 1000;
	table->sleep_time = ft_atoi(av[4]) * 1000;
	table->meals_target = ac == 6 ? ft_atoi(av[5]) : INT_MAX;
	table->time_zero = 0;
	table->alive_all = true_e;
	table->satisfied_all = false_e;
	table->satisfied_count = 0;
	i.alive = pthread_mutex_init(&table->use_alive, NULL);
	i.meals = pthread_mutex_init(&table->use_meals, NULL);
	i.print = pthread_mutex_init(&table->use_print, NULL);
	i.satisfied = pthread_mutex_init(&table->use_satisfied, NULL);
	i.time = pthread_mutex_init(&table->use_time, NULL);
	if (i.alive != 0 || i.meals != 0 || i.print != 0 \
	|| i.satisfied != 0 || i.time != 0)
		return (!print_mutexinierror(table));
	table->philos = (t_philo *)malloc(sizeof(t_philo) * (table->philos_n));
	if (!table->philos && print_mallocerror(table))
		return (free_all(table));
	return (true_e);
}

t_bool	init_philos(t_table *table)
{
	int		n;
	t_philo	*philo;

	n = 0;
	while (n < table->philos_n)
	{
		philo = &table->philos[n];
		if (pthread_create(&philo->philo_thread, NULL, philo_life, philo) != 0)
			return (free_all(table));
		philo->philo_n = n + 1;
		philo->meal_count = 0;
		philo->meal_last = 0;
		philo->alive_me = true_e;
		philo->satisfied_me = false_e;
		if (pthread_mutex_init(&philo->fork_l, NULL) != 0)
			return (free_all(table));
		table->philos[0].fork_r = &philo->fork_l;
		if (n > 0)
			philo->fork_r = &table->philos[n - 1].fork_l;
		n++;
	}
	return (true_e);
}
