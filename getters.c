/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getters.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvisca <mvisca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 12:57:51 by mvisca            #+#    #+#             */
/*   Updated: 2024/01/27 14:55:22 by mvisca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static long long	get_safe_aux3(t_table *t, int op, int chair)
{
	long long	count;

	if (op == P_MEAL_COUNT)
	{
		pthread_mutex_lock(&t->mtx_philo_meal);
		count = (long long) t->philos[chair].meals_count;
		pthread_mutex_unlock(&t->mtx_philo_meal);
	}
	else
		return (-1);
	return (count);
}

static long long	get_safe_aux2(t_table *t, int op, int chair)
{
	long long	count;
	
	if (op == COUNT_CHAIRS)
	{
		pthread_mutex_lock(&t->mtx_chairs);
		count = (long long) t->philos_n;
		pthread_mutex_unlock(&t->mtx_chairs);
	}
	else if (op == MAX_MEALS)
	{
		pthread_mutex_lock(&t->mtx_meals);
		count = (long long) t->max_meals;
		pthread_mutex_unlock(&t->mtx_meals);
	}
	else if (op == P_LAST_MEAL)
	{
		pthread_mutex_lock(&t->mtx_philo_meal);
		count = (long long) t->philos[chair].last_meal;
		pthread_mutex_unlock(&t->mtx_philo_meal);
	}
	else
		get_safe_aux3(t, op, chair);
	return (count);
}

static long long	get_safe_aux1(t_table *t, int op, int chair)
{
	long long	count;

	if (op == COUNT_DEAD)
	{
		pthread_mutex_lock(&t->mtx_dead);
		count = (long long) t->dead_count;
		pthread_mutex_unlock(&t->mtx_dead);
	}
	else if (op == COUNT_HUNGRY)
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
	}
	else
		count = get_safe_aux2(t, op, chair);
	return (count);
}

long long	get_safe(t_table *t, int op, int chair)
{
	long long	count;

	if (op == TIME_DIE)
	{
		pthread_mutex_lock(&t->mtx_die);
		count = (long long) t->die_time;
		pthread_mutex_unlock(&t->mtx_die);
	}
	else if (op == TIME_EAT)
	{
		pthread_mutex_lock(&t->mtx_eat);
		count = (long long) t->eat_time;
		pthread_mutex_unlock(&t->mtx_eat);
	}
	else if (op == TIME_SLEEP)
	{
		pthread_mutex_lock(&t->mtx_sleep);
		count = (long long) t->sleep_time;
		pthread_mutex_unlock(&t->mtx_sleep);
	}
	else
		count = get_safe_aux1(t, op, chair);
	return (count);
}
