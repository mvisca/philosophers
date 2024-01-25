/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvisca <mvisca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 17:22:59 by mvisca            #+#    #+#             */
/*   Updated: 2024/01/25 14:52:14 by mvisca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

int	ft_atoi(char *str)
{
	long long	result;
	int			i;

	result = 0;
	i = 0;
	while (str && ((str[i] >= 9 && str[i] <= 13) || str[i] == 32))
		i++;
	while (str && str[i])
	{
		result = (result * 10) + str[i] - '0';
		i++;
	}
	if (result < INT_MIN || result > INT_MAX)
		return (-1);
	return ((int) result);
}

int	free_all(t_table *table)
{
	int	n;

	pthread_mutex_destroy(&table->mtx_chairs);
	pthread_mutex_destroy(&table->mtx_dead);
	pthread_mutex_destroy(&table->mtx_die);
	pthread_mutex_destroy(&table->mtx_eat);
	pthread_mutex_destroy(&table->mtx_hungry);
	pthread_mutex_destroy(&table->mtx_meals);
	pthread_mutex_destroy(&table->mtx_print);
	pthread_mutex_destroy(&table->mtx_sleep);
	pthread_mutex_destroy(&table->mtx_start);
	n = 0;
	while (n < table->philos_n)
		pthread_mutex_destroy(&table->philos[n++].fork_l);
	free(table->philos);
	return (0);
}
