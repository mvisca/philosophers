/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvisca <mvisca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 17:22:32 by mvisca            #+#    #+#             */
/*   Updated: 2024/01/30 16:13:38 by mvisca-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	join_philos(t_table *table)
{
	int	n;

	n = 0;
	while (n < getint(table, COUNT_CHAIRS, 0))
	{
		if (pthread_join(table->philos[n].philo_thread, NULL) != 0)
		{
			printf("Error in pthread_join at index %d\n", n);
			free_all(table);
			return (1);
		}
		n++;
	}
	return (0);
}

void	running(t_table *t)
{
	int	i;

	pthread_mutex_lock(&t->mtx_end);
	while (pt_hungry(t))
	{
		i = 0;
		while (i < getint(t, COUNT_CHAIRS, 0))
		{
			if (p_dead(&t->philos[i], t))
				break ;
			i++;
		}
		if (pt_dead(t))
			break ;
	}
	pthread_mutex_unlock(&t->mtx_end);
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
	join_philos(&table);
	free_all(&table);
	return (0);
}
