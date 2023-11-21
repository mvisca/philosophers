/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_execute.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvisca-g <mvisca-g@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 20:23:28 by mvisca-g          #+#    #+#             */
/*   Updated: 2023/11/21 20:31:54 by mvisca-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

// sets the initial time for all philos
int	gym_execute(t_gym *gym)
{
	int	i;

	gym_forks_create(gym); // tenedores creados;
	gym_philos_create(gym);	// filósofos creados;
	i = 0;
	while (i < gym->total_philos)
	{
		pthread_join
		i++;
	}
	gym_thread_destroy(gym);
	return (0);
}
