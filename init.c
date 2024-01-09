/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvisca <mvisca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 17:21:51 by mvisca            #+#    #+#             */
/*   Updated: 2024/01/09 18:52:45 by mvisca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_bool	init_table(int ac, char **av, t_table *table)
{
	if (!validate_args(ac, av))
		return (false_e);
	table->run = true_e;
	table->philos_n = ft_atoi(av[1]);
	table->philos = (t_philo *) malloc (sizeof(struct s_philo) * (table->philos_n + 1));
	if (!table->philos && print_mallocerror(table))
		return (false_e);
	table->time_zero = 0;
	table->time_die = ft_atoi(av[2]) * 1000;
	table->time_eat = ft_atoi(av[3]) * 1000;
	table->time_sleep = ft_atoi(av[4]) * 1000;
	table->total_meals = -1;
	table->philos_done = 0;
	if (ac == 6)
		table->total_meals = ft_atoi(av[5]);
	if (pthread_mutex_init(&table->print, NULL) != 0)
		print_mutexinierror(table);
	if (pthread_mutex_init(&table->stop_run, NULL) != 0)
		print_mutexinierror(table);
	if (pthread_mutex_init(&table->count, NULL) != 0)
		print_mutexinierror(table);
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
		if (table->philos_n == 1 && print_die(philo))
			return (free_all(table));
		table->philos[0].right_f = &philo->left_f;
		if (n > 0)
			philo->right_f = &table->philos[n - 1].left_f;
		n++;
		if (pthread_create(&philo->p_thread, NULL, philo_life, philo) != 0)
			return (free_all(table));
	}
}
