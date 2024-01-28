/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvisca <mvisca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 17:22:32 by mvisca            #+#    #+#             */
/*   Updated: 2024/01/27 14:58:34 by mvisca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	join_philos(t_table *table)
{
	int	n;

	n = 0;
	while (n < (int) get_safe(table, COUNT_CHAIRS, 0))
	{
		if (pthread_join(table->philos[n].philo_thread, NULL) != 0)
		{
			printf("Error in pthread_join at index %d\n", n);
			free_all(table);
			return (1);
		}
		printf("hilo recogido %d\n", n);
		n++;
	}
	return (0);
}

void	running(t_table *t)
{
	int	i;

	printf("activa running\n");
	pthread_mutex_lock(&t->mtx_end);
	while ((int) get_safe(t, COUNT_HUNGRY, 0) != 0 \
	&& get_safe(t, COUNT_DEAD, 0) == 0)
	{
		i = 0;
		while (i < (int) get_safe(t, COUNT_CHAIRS, 0))
		{
			if (time_now(t) - t->philos[i].last_meal > (int) get_safe(t, TIME_DIE, 0))
			{
				pthread_mutex_lock(&t->mtx_dead);
				philo_die(&t->philos[i]); // DEAD == 1
				pthread_mutex_unlock(&t->mtx_dead);
				break ;
			}
			i++;
		}
	}
	printf("saliendo de running\n");

	ft_usleep((int) get_safe(t, TIME_DIE, 0), t);
	pthread_mutex_unlock(&t->mtx_end);
}


int	main(int ac, char **av)
{
	t_table	table;

	if (validate_args(ac, av))
		return (11);
	if (init_table(ac, av, &table) || init_philos(&table))
	{
		free_all(&table); // condicion para vaciar philo[n] si es null que no lo haga
		return (12);
	}
	running(&table);
	join_philos(&table);
	free_all(&table);
	return (0);
}

	// pthread_mutex_lock(&table.mtx_time);
	// table.start_time = time_now();
	// pthread_mutex_unlock(&table.mtx_time);
	// printf("IN1\n");
