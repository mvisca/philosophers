/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvisca <mvisca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 17:21:38 by mvisca            #+#    #+#             */
/*   Updated: 2024/01/23 02:35:31 by mvisca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_bool	print_argserror(void)
{

	printf("Wrong number of arguments. Instead use:\n");
	printf("./philo [n_philos] [t_die] [t_eat] [t_sleep] [n_meals*]\n");
	printf("*Optional.\n");
	return (true_e);
}

t_bool	print_charerror(void)
{
	printf("Wrong set of chars. Use only digits.\n");
	return (true_e);
}

t_bool	print_mallocerror(t_table *table)
{
	printf("Ups! Error while allocating memory.\n");
	free_all(table);
	return (true_e);
}

t_bool	print_mutexinierror(t_table *table)
{
	int	n;

	pthread_mutex_destroy(&table->use_alive);
	pthread_mutex_destroy(&table->use_hungry);
	pthread_mutex_destroy(&table->use_meals);
	pthread_mutex_destroy(&table->use_print);
	pthread_mutex_destroy(&table->use_time);
	printf("Ups! Error while initializing mutex\n");
	if (table->philos)
	{
		n = 0;
		while(n < table->philos_n)
		{
			pthread_mutex_destroy(&table->philos[n].fork_l);
			n++;
		}
	}
	free_all(table);
	return (true_e);
}

t_bool	print_maxerror(void)
{
	printf("Number of philos: max = 200, min = 1.\nNumber of meals: min = 1.\n");
	return (true_e);
}
