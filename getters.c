/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getters.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvisca <mvisca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 12:57:51 by mvisca            #+#    #+#             */
/*   Updated: 2024/01/25 14:55:13 by mvisca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static long long	get_sage_aux2(t_table *t, int op)
{
	long long	count;
	
	if (op == CHAIRS)
	{
		pthread_mutex_lock(&t->mtx_chairs);
		count = (long long) t->philos_n;
		pthread_mutex_unlock(&t->mtx_chairs);
	}
	else if (op == MEALS)
	{
		pthread_mutex_lock(&t->mtx_meals);
		count = (long long) t->max_meals;
		pthread_mutex_unlock(&t->mtx_meals);
	}
	else
		return (-1);
	return (count);
}

static long long	get_safe_aux1(t_table *t, int op)
{
	long long	count;

	if (op == DEAD)
	{
		pthread_mutex_lock(&t->mtx_dead);
		count = (long long) t->dead_count;
		pthread_mutex_unlock(&t->mtx_dead);
	}
	else if (op == HUNGRY)
	{
		pthread_mutex_lock(&t->mtx_hungry);
		count = (long long) t->hungry_count;
		pthread_mutex_unlock(&t->mtx_hungry);
	}
	else if (op == START)
	{
		pthread_mutex_lock(&t->mtx_start);
		count = t->start_time;
		pthread_mutex_unlock(&t->mtx_start);
		printf(">> Get safe START %d\n", (int) count);
	}
	else
		count = get_sage_aux2(t, op);
	return (count);
}

long long	get_safe(t_table *t, int op)
{
	long long	count;

	if (op == DIE)
	{
		pthread_mutex_lock(&t->mtx_die);
		count = (long long) t->die_time;
		pthread_mutex_unlock(&t->mtx_die);
		printf(">> Get safe DIE %d\n", (int) count);
	}
	else if (op == EAT)
	{
		pthread_mutex_lock(&t->mtx_eat);
		count = (long long) t->eat_time;
		pthread_mutex_unlock(&t->mtx_eat);
		printf(">> Get safe EAT %d\n", (int) count);
	}
	else if (op == SLEEP)
	{
		pthread_mutex_lock(&t->mtx_sleep);
		count = (long long) t->sleep_time;
		pthread_mutex_unlock(&t->mtx_sleep);
		printf(">> Get safe SLEEP %d\n", (int) count);
	}
	else
		count = get_safe_aux1(t, op);
	return (count);
}
