/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_destroy.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvisca-g <mvisca-g@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 19:49:41 by mvisca-g          #+#    #+#             */
/*   Updated: 2023/11/21 20:19:18 by mvisca-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	gym_forks_destroy(t_gym *gym)
{
	int	i;

	i = 0;
	while (i < gym->total_philos)
	{
		if (pthread_mutex_destroy(&gym->forks[i]) != 0)
			error_exit("Error: destroying forks\n", 20000 + i);
		i++;
	}
	printf("All forks destroyed\n");
	return (0);
}
