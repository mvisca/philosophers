/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvisca <mvisca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 17:22:32 by mvisca            #+#    #+#             */
/*   Updated: 2024/01/30 00:37:59 by mvisca           ###   ########.fr       */
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
	// printf("Hungry %d \n", (getint(t, COUNT_HUNGRY, 0)));
	// printf("Dead %d \n", (getint(t, COUNT_DEAD, 0)));
	// printf("Valor %s \n", (getint(t, COUNT_HUNGRY, 0) != 0 && getint(t, COUNT_DEAD, 0) == 0) ? "true" : "false");
	while (pt_hungry(t))
	{
		i = 0;
		while (i < getint(t, COUNT_CHAIRS, 0))
		{
			if (p_dead(&t->philos[i], t))
			{
				// pthread_mutex_lock(&t->mtx_dead);
				// philo_die(&t->philos[i]);
				// pthread_mutex_unlock(&t->mtx_dead);
				break ;
			}
			i++;
		}
		if (pt_dead(t))
			break ;
	}
	pthread_mutex_unlock(&t->mtx_end);
}

// static void	print_data(t_table *t)
// {
// 	printf("t->dead_count %d\n", t->dead_count);
// 	printf("t->hungry_count %d\n", t->hungry_count);
// 	printf("t->max_meals %d\n", t->max_meals);
// 	printf("t->die_time %d\n", t->die_time);
// 	printf("t->eat_time %d\n", t->eat_time);
// 	printf("t->sleep_time %d\n", t->sleep_time);
// 	printf("t->start_time %lld\n", t->start_time);
// 	printf("t->philos_n %d\n", t->philos_n);
// 	int i = 0;
// 	while (i < t->philos_n)
// 	{
// 		printf("\nphilos[%d].fork_r\n", t->philos[i].chair);	
// 		printf("philos[n].fork_l %p\n", &t->philos[i].fork_l);
// 		printf("philos[n].fork_r %p\n", t->philos[i].fork_r);
// 		printf("philos[n].last_meal %lld\n", t->philos[i].last_meal);
// 		printf("philos[n].meals_count %d\n", t->philos[i].meals_count);
// 		printf("philos[n].philo_thread %p\n", &t->philos[i].philo_thread);
// 		i++;
// 	}
// }

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
//	print_data(&table);
	running(&table);

	// int x = 0;
	// while (x < table.philos_n)
	// {
	// 	printf("\tphilo %d meals %d\n", x + 1, table.philos[x].meals_count);
	// 	x++;
	// }
	// printf("table hungry %d\n", table.hungry_count);
	// printf("table dead %d\n", table.dead_count);

	join_philos(&table);
	free_all(&table);
	return (0);
}
