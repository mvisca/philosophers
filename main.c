/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvisca <mvisca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 17:22:32 by mvisca            #+#    #+#             */
/*   Updated: 2024/01/22 23:08:11 by mvisca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_table	table;

	if (!validate_args(ac, av))
		return (1);	
	if (!init_table(ac, av, &table))
		return (1);
	if (!init_philos(&table))
		return (1);

	pthread_mutex_lock(&table.use_time);
	table.time_zero = time_now();
	pthread_mutex_unlock(&table.use_time);

	join_philos(&table);
	
	free_all(&table);
	return (0);
}
