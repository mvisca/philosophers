/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getters.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvisca-g <mvisca-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 12:57:51 by mvisca            #+#    #+#             */
/*   Updated: 2024/02/02 20:01:28 by mvisca-g         ###   ########.fr       */
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
		return (write(2, "Argumento de getlong inválido\n", 30));
	return (count);
}

static long long	getint2(t_table *t, int op, int chair)
{
	long long	count;

	if (op == MAX_MEALS)
	{
		pthread_mutex_lock(&t->mtx_meals);
		count = t->max_meals;
		pthread_mutex_unlock(&t->mtx_meals);
	}
	else if (op == P_MEAL_COUNT)
	{
		pthread_mutex_lock(&t->mtx_philo_meal);
		count = t->philos[chair - 1].meals_count;
		pthread_mutex_unlock(&t->mtx_philo_meal);
	}
	else
		return (printf("Argumento de getlong inválido"));
	return (count);
}

static int	getint1(t_table *t, int op, int chair)
{
	int	count;

	if (op == COUNT_DEAD)
	{
		pthread_mutex_lock(&t->mtx_dead);
		count = t->dead_count;
		pthread_mutex_unlock(&t->mtx_dead);
	}
	else if (op == COUNT_HUNGRY)
	{
		pthread_mutex_lock(&t->mtx_hungry);
		count = t->hungry_count;
		pthread_mutex_unlock(&t->mtx_hungry);
	}
	else if (op == COUNT_CHAIRS)
	{
		pthread_mutex_lock(&t->mtx_chairs);
		count = t->philos_n;
		pthread_mutex_unlock(&t->mtx_chairs);
	}
	else
		count = getint2(t, op, chair);
	return (count);
}

int	getint(t_table *t, int op, int chair)
{
	int	count;

	if (op == TIME_DIE)
	{
		pthread_mutex_lock(&t->mtx_die);
		count = t->die_time;
		pthread_mutex_unlock(&t->mtx_die);
	}
	else if (op == TIME_EAT)
	{
		pthread_mutex_lock(&t->mtx_eat);
		count = t->eat_time;
		pthread_mutex_unlock(&t->mtx_eat);
	}
	else if (op == TIME_SLEEP)
	{
		pthread_mutex_lock(&t->mtx_sleep);
		count = t->sleep_time;
		pthread_mutex_unlock(&t->mtx_sleep);
	}
	else
		count = getint1(t, op, chair);
	return (count);
}
