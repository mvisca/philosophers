/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvisca <mvisca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 17:21:51 by mvisca            #+#    #+#             */
/*   Updated: 2024/01/23 20:26:53 by mvisca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_table(int ac, char **av, t_table *table)
{
	t_ints	i;

	table->philos_n = ft_atoi(av[1]);
	table->die_time = ft_atoi(av[2]);
	table->eat_time = ft_atoi(av[3]);
	table->sleep_time = ft_atoi(av[4]);
	table->max_meals = ac == 6 ? ft_atoi(av[5]) : INT_MAX;
	table->start_time = 0;
	table->dead_count = 0;
	table->hungry_count = table->philos_n;
	i.print = pthread_mutex_init(&table->mtx_print, NULL);
	i.run = pthread_mutex_init(&table->mtx_run, NULL);
	if (i.print != 0 || i.run != 0)
	{
		printf("error en creacion de mutex\n");
		return (!print_mutexinierror(table));
	}
	table->philos = (t_philo *)malloc(sizeof(t_philo) * (table->philos_n));
	if (!table->philos && print_mallocerror(table))
		return (free_all(table));
	return (0);
}

int	init_philos(t_table *table)
{
	int		n;
	t_philo	*philo;

	n = 0;
	while (n < table->philos_n)
	{
		philo = &table->philos[n];
		if (pthread_create(&philo->philo_thread, NULL, philo_life, philo) != 0)
			return (free_all(table));
		philo->chair = n + 1;
		philo->meals_count = 0;
		philo->last_meal = 0;
		if (pthread_mutex_init(&philo->fork_l, NULL) != 0)
			return (free_all(table));
		table->philos[0].fork_r = &philo->fork_l;
		if (n > 0)
			philo->fork_r = &table->philos[n - 1].fork_l;
		philo->t = table;
		n++;
	}
	return (0);
}
