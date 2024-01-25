/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvisca <mvisca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 17:22:32 by mvisca            #+#    #+#             */
/*   Updated: 2024/01/25 14:32:24 by mvisca           ###   ########.fr       */
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

	while (get_safe(t, HUNGRY) > 0 && get_safe(t, DEAD) == 0)
	{
		i = 0;
		while (i < (int) get_safe(t, CHAIRS))
		{
			if (time_now() - t->philos[i].last_meal > (int) get_safe(t, DIE))
			{
				pthread_mutex_lock(&t->mtx_dead);
				dead_philo(&t->philos[i]);
				pthread_mutex_unlock(&t->mtx_dead);
				break ;
			}
		}
	}
}

int	main(int ac, char **av)
{
	printf("now start %lld\n", time_now());
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
	printf("now end %lld\n", time_now());
	printf("execution %lld\n", get_time(&table));
	free_all(&table);
	return (0);
}

	// pthread_mutex_lock(&table.mtx_time);
	// table.start_time = time_now();
	// pthread_mutex_unlock(&table.mtx_time);
	// printf("IN1\n");
