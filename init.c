/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvisca <mvisca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 17:21:51 by mvisca            #+#    #+#             */
/*   Updated: 2024/01/25 14:53:29 by mvisca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	init_mutex(t_table *table)
{
	t_ints	i;

	i.ch = pthread_mutex_init(&table->mtx_chairs, NULL);
	i.de = pthread_mutex_init(&table->mtx_dead, NULL);
	i.di = pthread_mutex_init(&table->mtx_die, NULL);
	i.ea = pthread_mutex_init(&table->mtx_eat, NULL);
	i.hu = pthread_mutex_init(&table->mtx_hungry, NULL);
	i.me = pthread_mutex_init(&table->mtx_meals, NULL);
	i.sl = pthread_mutex_init(&table->mtx_print, NULL);
	i.st = pthread_mutex_init(&table->mtx_sleep, NULL);
	i.pr = pthread_mutex_init(&table->mtx_start, NULL);
	if (i.ch != 0 || i.de != 0 || i.di != 0 || i.ea != 0 \
		|| i.hu != 0 || i.me != 0 || i.sl != 0 || i.st != 0 || i.pr != 0)
		return (printf("error en creacion de mutex\n"));
	return (0);
}

int	init_table(int ac, char **av, t_table *table)
{
	table->philos_n = ft_atoi(av[1]); // CHAIRS_
	table->die_time = ft_atoi(av[2]); // DIE_
	table->eat_time = ft_atoi(av[3]); // EAT_
	table->sleep_time = ft_atoi(av[4]); // SLEEP_
	table->max_meals = INT_MAX; // MEALS_
	if (ac == 6)
		table->max_meals = ft_atoi(av[5]); // MEALS_
	table->start_time = time_now(); // START_
	table->dead_count = 0; // DEAD_
	table->hungry_count = table->philos_n; // HUNGRY_
	if (init_mutex(table) != 0)
		return (printf("error init mutexes"));
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
	while (n < get_safe(table, CHAIRS))
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
