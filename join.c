/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvisca <mvisca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 17:22:20 by mvisca            #+#    #+#             */
/*   Updated: 2024/01/19 01:55:20 by mvisca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

t_bool	join_philos(t_table *table)
{
	int	n;

	n = 0;
	printf("in join\n");
	while (n < table->philos_n)
	{
		if (pthread_join(table->philos[n].p_thread, NULL) != 0)
		{
			printf("Error in pthread_join at index %d\n", n);
			free_all(table);
			return (false_e) ;
		}
		printf("hilo recogido %d\n", n);
		n++;
	}
	return (true_e);
}
