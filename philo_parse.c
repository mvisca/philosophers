/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_parse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvisca <mvisca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 09:12:19 by mvisca            #+#    #+#             */
/*   Updated: 2023/11/19 23:56:06 by mvisca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	philos_init(t_gym *gym)
{
	int	i;

	gym->philos = (t_philo **)malloc(sizeof(t_philo *) * (gym->total_philos + 1));
	if (!gym->philos)
		error_exit("Error: malloc en philos_init() 1", 9);
	i = 0;
	while (i < gym->total_philos)
	{
		gym->philos[i] = (t_philo *)malloc(sizeof(t_philo));
		if (!gym->philos[i])
			error_exit("Error: malloc en philos_init() 2", 10);
		gym->philos[i]->philo_thread = NULL;
		gym->philos[i]->philo_index = i + 1;
		gym->philos[i]->is_alive = -1;
		gym->philos[i]->is_done = -1;
		gym->philos[i]->last_meal = 0;
		i++;
	}
	gym->philos[i] = NULL;
	return (0);
}

int	gym_init(t_gym *gym, int ac, char **av)
{
	if (ac < 5 || ac > 6)
		return (command_args_error());
	gym->philos = NULL;
	gym->forks = (pthread_mutex_t *)malloc \
		(sizeof(pthread_mutex_t) * gym->total_philos);
	if (!gym->forks)
		error_exit("Error: malloc en gym init forks", 18);
	gym->printing = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
	if (!gym->printing)
		error_exit("Error: malloc en gym init printing", 19);
	gym->total_philos = ft_atoi(av[1]);
	if (gym->total_philos < 2)
		error_exit("Error: número insuficiente de filósofos", 5);
	gym->open_time = 0;
	gym->time_to_die = ft_ato64(av[2]);
	gym->time_to_eat = ft_ato64(av[3]);
	gym->time_to_sleep = ft_ato64(av[4]);
	gym->meals_to_be_done = -1;
	if (ac == 6)
		gym->meals_to_be_done = ft_atoi(av[5]);
	philos_init(gym);
	return (0);
}
 