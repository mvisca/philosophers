/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getters_long.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvisca <mvisca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 20:20:08 by mvisca            #+#    #+#             */
/*   Updated: 2024/01/30 16:19:46 by mvisca-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long	getlong(t_table *t, int op, int chair)
{
	long long	count;

	if (op == NOW)
	{
		pthread_mutex_lock(&t->mtx_now);
		count = time_now();
		pthread_mutex_unlock(&t->mtx_now);
	}
	else if (op == START)
	{
		pthread_mutex_lock(&t->mtx_start);
		count = t->start_time;
		pthread_mutex_unlock(&t->mtx_start);
	}
	else if (op == P_LAST_MEAL)
	{
		pthread_mutex_lock(&t->mtx_philo_meal);
		count = t->philos[chair - 1].last_meal;
		pthread_mutex_unlock(&t->mtx_philo_meal);
	}
	else
		return (printf("Argumento de getlong inválido"));
	return (count);
}
