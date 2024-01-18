/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvisca <mvisca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 17:21:51 by mvisca            #+#    #+#             */
/*   Updated: 2024/01/16 19:40:10 by mvisca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_bool	init_table(int ac, char **av, t_table *table)
{
	t_ints	i;

	table->philos_n = ft_atoi(av[1]);
	table->time_die = ft_atoi(av[2]) * 1000;
	table->time_eat = ft_atoi(av[3]) * 1000;
	table->time_sleep = ft_atoi(av[4]) * 1000;
	table->time_zero = 0;
	table->run = true_e;
	table->philos_done = 0;
	table->total_meals = ac == 6 ? ft_atoi(av[5]) : -1;
	i.count = pthread_mutex_init(&table->count, NULL);
	i.print = pthread_mutex_init(&table->print, NULL);
	i.stop_run = pthread_mutex_init(&table->stop_run, NULL);
	i.time = pthread_mutex_init(&table->time, NULL);
	if (i.count != 0 || i.print != 0 || i.stop_run != 0 || i.time != 0)
		return (!print_mutexinierror(table));
	table->philos = (t_philo *)malloc(sizeof(t_philo) * (table->philos_n));
	if (!table->philos && print_mallocerror(table))
		return (free_all(table));
	return (true_e);
}

static t_bool	only_one(t_philo *philo)
{
	philo->table->time_zero = time_now();
	print_fork(philo);
	ft_usleep(philo->table->time_die);
	print_die(philo);
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
		philo->table = table;
		philo->chair_num = n + 1;
		philo->last_meal = -1;
		philo->meals_count = 0;
		if (pthread_mutex_init(&philo->left_f, NULL) != 0)
			return (free_all(table));
		table->philos[0].right_f = &philo->left_f;
		if (n > 0)
			philo->right_f = &table->philos[n - 1].left_f;
		if (pthread_create(&philo->p_thread, NULL, philo_life, philo) != 0)
			return (free_all(table));
		n++;
	}
	return (true_e);
}
