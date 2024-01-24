/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvisca <mvisca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 17:21:51 by mvisca            #+#    #+#             */
/*   Updated: 2024/01/24 18:26:34 by mvisca           ###   ########.fr       */
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
	table->max_meals = INT_MAX;
	if (ac == 6)
		table->max_meals = ft_atoi(av[5]);
	table->start_time = time_now();
	table->dead_count = 0;
	table->hungry_count = table->philos_n;
	i.print = pthread_mutex_init(&table->mtx_print, NULL);
	i.dead = pthread_mutex_init(&table->mtx_dead, NULL);
	i.time = pthread_mutex_init(&table->mtx_time, NULL);
	i.hungry = pthread_mutex_init(&table->mtx_hungry, NULL);
	if (i.print != 0 || i.dead != 0 || i.time != 0 || i.hungry != 0)
		return (printf("error en creacion de mutex\n"));
	table->philos = (t_philo *)malloc(sizeof(t_philo) * (table->philos_n));
	if (!table->philos)
		return (printf("malloc error init philo\n"));
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
		philo->t = table;
		philo->chair = n + 1;
		philo->meals_count = 0;
		philo->last_meal = get_safe(table, START);
		if (pthread_mutex_init(&philo->fork_l, NULL) != 0)
			return (free_all(table));
		if (n > 0)
			philo->fork_r = &table->philos[n - 1].fork_l;
		table->philos[0].fork_r = &philo->fork_l;
		if (pthread_create(&philo->philo_thread, NULL, philo_life, philo) != 0)
			return (printf("error al crear hilos en inti philos\n"));
		n++;
	}
	return (0);
}
