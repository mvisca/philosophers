/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvisca <mvisca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 17:21:38 by mvisca            #+#    #+#             */
/*   Updated: 2024/01/24 18:35:08 by mvisca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	print_argserror(void)
{
	printf("Wrong number of arguments. Instead use:\n");
	printf("./philo [n_philos] [t_die] [t_eat] [t_sleep] [n_meals*]\n");
	printf("*Optional.\n");
	return (1);
}

int	print_charerror(void)
{
	printf("Wrong set of chars. Use only digits.\n");
	return (1);
}

int	print_mallocerror(t_table *table)
{
	printf("Ups! Error while allocating memory.\n");
	return (1);
}

int	print_mutexinierror(t_table *table)
{
	printf("Ups! Error while initializing mutex\n");
	return (1);
}

int	print_maxerror(void)
{
	printf("Number of philos: max = 200, min = 1.\nNumber of meals: min = 1.\n");
	return (1);
}
