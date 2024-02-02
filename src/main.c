/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvisca-g <mvisca-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 17:22:32 by mvisca            #+#    #+#             */
/*   Updated: 2024/02/02 19:56:55 by mvisca-g         ###   ########.fr       */
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
			write(2, "Error: in pthread_join", 22);
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
	int	chairs;

	pthread_mutex_lock(&t->mtx_end);
	chairs = getint(t, COUNT_CHAIRS, 0);
	while (pt_hungry(t))
	{
		i = 0;
		while (i < chairs)
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
