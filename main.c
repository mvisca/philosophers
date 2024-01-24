/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvisca <mvisca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 17:22:32 by mvisca            #+#    #+#             */
/*   Updated: 2024/01/24 18:28:26 by mvisca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	join_philos(t_table *table)
{
	int	n;

	n = 0;
	printf("in join\n");
	while (n < table->philos_n)
	{
		if (pthread_join(table->philos[n].philo_thread, NULL) != 0)
		{
			printf("Error in pthread_join at index %d\n", n);
			free_all(table);
			return (0);
		}
		printf("hilo recogido %d\n", n);
		n++;
	}
	return (1);
}

void	running(t_table *t)
{
	int	i;
	int	count;

	count = get_safe(t, HUNGRY);
	while (count != 0)
	{
		i = 0;
		count = get_safe(t, DEAD);
		while (i < t->philos_n && count == 0)
		{
			pthread_mutex_lock(&t->mtx_dead);
			dead_philo(&t->philos[i++]);
			count = t->dead_count;
			pthread_mutex_unlock(&t->mtx_dead);
		}
		if (count != 0)
			break ;
		count = get_safe(t, HUNGRY);
	}
}

int	main(int ac, char **av)
{
	t_table	table;

	if (validate_args(ac, av))
		return (11);
	if (init_table(ac, av, &table) || init_philos(&table))
	{
		free_all(&table);
		return (12);
	}
	running(&table);
	printf("PASS TABLE\n");
	join_philos(&table);
	free_all(&table);
	return (0);
}

	// pthread_mutex_lock(&table.mtx_time);
	// table.start_time = time_now();
	// pthread_mutex_unlock(&table.mtx_time);
	// printf("IN1\n");
