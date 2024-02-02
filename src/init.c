/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvisca-g <mvisca-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 17:21:51 by mvisca            #+#    #+#             */
/*   Updated: 2024/02/02 19:35:35 by mvisca-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	init_mutex(t_table *table)
{
	t_ints	i;

	i.cch = pthread_mutex_init(&table->mtx_chairs, NULL);
	i.cde = pthread_mutex_init(&table->mtx_dead, NULL);
	i.chu = pthread_mutex_init(&table->mtx_hungry, NULL);
	i.end = pthread_mutex_init(&table->mtx_end, NULL);
	i.pm = pthread_mutex_init(&table->mtx_philo_meal, NULL);
	i.tdi = pthread_mutex_init(&table->mtx_die, NULL);
	i.tea = pthread_mutex_init(&table->mtx_eat, NULL);
	i.str = pthread_mutex_init(&table->mtx_sleep, NULL);
	i.mxm = pthread_mutex_init(&table->mtx_meals, NULL);
	i.nw = pthread_mutex_init(&table->mtx_now, NULL);
	i.pr = pthread_mutex_init(&table->mtx_start, NULL);
	i.tsl = pthread_mutex_init(&table->mtx_print, NULL);
	if (i.cch || i.cde || i.chu || i.end || i.pm || i.tdi || i.tea || i.tsl \
			|| i.mxm || i.str || i.pr)
		return (1);
	return (0);
}

int	init_table(int ac, char **av, t_table *table)
{
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
	if (init_mutex(table) != 0)
		return (write(2, "Error: init mutexes\n", 20));
	table->philos = (t_philo *) malloc (sizeof(t_philo) * ft_atoi(av[1]));
	if (!table->philos)
		return (write(2, "Error: malloc error init philo\n", 31));
	return (0);
}

static int	prev_n(t_table *table, int n)
{
	int	pn;

	pn = table->philos_n;
	return ((n + pn - 1) % pn);
}

int	init_philos(t_table *table)
{
	int		n;
	t_philo	*philo;

	n = 0;
	while (n < getint(table, COUNT_CHAIRS, 0))
	{
		if (pthread_mutex_init(&table->philos[n].fork_l, NULL) != 0)
			return (printf("Error creando mutex"));
		n++;
	}
	n = 0;
	while (n < getint(table, COUNT_CHAIRS, 0))
	{
		philo = &table->philos[n];
		philo->t = table;
		philo->chair = n + 1;
		philo->meals_count = 0;
		philo->last_meal = getlong(table, START, 0);
		philo->fork_r = &table->philos[prev_n(table, n)].fork_l;
		if (pthread_create(&philo->philo_thread, NULL, philo_life, philo) != 0)
			return (printf("error al crear hilos en inti philos\n"));
		n++;
	}
	return (0);
}
