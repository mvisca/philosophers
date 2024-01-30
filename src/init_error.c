/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvisca <mvisca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 17:21:38 by mvisca            #+#    #+#             */
/*   Updated: 2024/01/30 15:50:54 by mvisca-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	print_argserror(void)
{
	write(2, "Wrong number of arguments. Instead use:\n", 40);
	write(2, "./philo [n_philos] [t_die] [t_eat] [t_sleep] [n_meals*]\n", 56);
	write(2, "*Optional\n", 10);
	return (1);
}

int	print_charerror(void)
{
	write(2, "Wrong set of chars. Use only digits\n", 36);
	return (1);
}

int	print_mallocerror(void)
{
	write(2, "Error while allocating memory\n", 30);
	return (1);
}

int	print_mutexinierror(void)
{
	write(2, "Error while initializing mutex\n", 31);
	return (1);
}

int	print_maxerror(void)
{
	write(2, "Number of philos: max = 200, min = 1\n", 37);
	write(2, "Number of meals: min = 1\n", 25);
	return (1);
}
