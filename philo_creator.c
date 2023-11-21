/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_creator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvisca-g <mvisca-g@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 17:56:37 by mvisca-g          #+#    #+#             */
/*   Updated: 2023/11/21 20:31:57 by mvisca-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	gym_philos_create(t_gym *gym)
{
	int	i;

	i = 0;
	while (i < gym->total_philos)
	{
		gym->philos[i]->philo_thread = (pthread_t *)malloc(sizeof(pthread_t));
		if (!gym->philos[i]->philo_thread)
			error_exit("Error: malloc at gym_open\n", 16);
		if (pthread_create(gym->philos[i]->philo_thread, NULL, &gym_table, NULL))
			error_exit("Error: creating thread\n", 17000 + i);	
		gym->philos[i]->is_alive = 1;
		gym->philos[i]->is_done = 0;
		gym->philos[i]->last_meal = 0;
		i++;
	}
	gym->open_time = gym_gettime();
	return (0);
}

int	gym_forks_create(t_gym *gym)
{
	int	i;

	i = 0;
	while (i < gym->total_philos)
	{
		if (pthread_mutex_init(&gym->forks[i], NULL))
			error_exit("Error: mutex creation\n", 18);
		i++;
	}
	return (0);
}

