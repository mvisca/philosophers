/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvisca <mvisca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 17:22:20 by mvisca            #+#    #+#             */
/*   Updated: 2024/01/23 19:12:51 by mvisca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

int join_philos(t_table *table)
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
