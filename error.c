/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvisca <mvisca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 17:21:38 by mvisca            #+#    #+#             */
/*   Updated: 2024/01/09 18:28:26 by mvisca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_bool	print_argserror(void)
{

	printf("Wrong number of arguments\n");
	printf("./philo [n_philos] [t_die] [t_eat] [t_sleep] [n_meals]*\n");
	printf("* - Optional\n");
	return (true_e);
}

t_bool	print_charerror(void)
{
	printf("Wrong set of char, use only digits\n");
	return (true_e);
}

t_bool	print_mallocerror(t_table *table)
{
	printf("Error while allocating memory\n");
	free_all(table);
	return (true_e);
}

t_bool	print_mutexinierror(t_table *table)
{
	printf("Error while initializing mutex\n");
	free_all(table);
	return (true_e);
}

t_bool	print_maxerror(void)
{
	printf("n_philos must be > 0 && < 201\nn_meals must be > 0\n");
	return (true_e);
}
