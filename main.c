/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvisca <mvisca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 17:22:32 by mvisca            #+#    #+#             */
/*   Updated: 2024/01/24 13:03:55 by mvisca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_table	table;

	if (validate_args(ac, av))
		return (11);
	printf("IN");
	if (!init_table(ac, av, &table) && !init_philos(&table))
	{
		free_all(&table);
		return (12);
	}
	pthread_mutex_lock(&table.mtx_run);
	table.start_time = time_now();
	pthread_mutex_unlock(&table.mtx_run);
	running(&table);
	join_philos(&table);
	free_all(&table);
	return (0);
}
