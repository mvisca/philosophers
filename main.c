/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvisca <mvisca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 17:22:32 by mvisca            #+#    #+#             */
/*   Updated: 2024/01/22 21:19:06 by mvisca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_table	table;

	if (!validate_args(ac, av))
		return (false_e);	
	if (init_table(ac, av, &table) && init_philos(&table))
	{

		pthread_mutex_lock(&table.print);

		table.time_zero = time_now();

		printf("\tpunto 4\n");
		printf("\tLanzando time_zero\n");

		pthread_mutex_unlock(&table.print);

		join_philos(&table);

		printf("punto 5\n");

		free_all(&table);
		return (0);
	}
	return (1);
}
