/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvisca <mvisca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 17:22:20 by mvisca            #+#    #+#             */
/*   Updated: 2024/01/23 02:34:13 by mvisca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

void	philo_alone(t_philo *philo)
{
	print_fork(philo);
	ft_usleep(philo->t->die_time);
	print_die(philo);
	philo->alive_me = false_e;
	philo->t->alive_all = false_e;
}

t_bool	join_philos(t_table *table)
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
			return (false_e);
		}
		printf("hilo recogido %d\n", n);
		n++;
	}
	return (true_e);
}
