/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvisca <mvisca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 17:22:59 by mvisca            #+#    #+#             */
/*   Updated: 2024/01/24 18:29:27 by mvisca           ###   ########.fr       */
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

	pthread_mutex_destroy(&table->mtx_dead);
	pthread_mutex_destroy(&table->mtx_print);
	pthread_mutex_destroy(&table->mtx_time);
	pthread_mutex_destroy(&table->mtx_hungry);
	n = 0;
	while (n < table->philos_n)
		pthread_mutex_destroy(&table->philos[n++].fork_l);
	free(table->philos);
	return (0);
}

static int	get_safe_aux(t_table *t, int op)
{
	int	count;

	if (op == DEAD)
	{
		pthread_mutex_lock(&t->mtx_dead);
		count = t->dead_count;
		pthread_mutex_unlock(&t->mtx_dead);
	}
	if (op == DIE)
	{
		pthread_mutex_lock(&t->mtx_time);
		count = t->die_time;
		pthread_mutex_unlock(&t->mtx_time);
	}
	if (op == START)
	{
		pthread_mutex_lock(&t->mtx_time);
		count = t->start_time;
		pthread_mutex_unlock(&t->mtx_time);
	}
	else
		count = -1;
	return (count);
}

int	get_safe(t_table *t, int op)
{
	int	count;

	if (op == HUNGRY)
	{
		pthread_mutex_lock(&t->mtx_hungry);
		count = t->hungry_count;
		pthread_mutex_unlock(&t->mtx_hungry);
	}
	else if (op == EAT)
	{
		pthread_mutex_lock(&t->mtx_time);
		count = t->eat_time;
		pthread_mutex_unlock(&t->mtx_time);
	}
	else if (op == SLEEP)
	{
		pthread_mutex_lock(&t->mtx_time);
		count = t->sleep_time;
		pthread_mutex_unlock(&t->mtx_time);
	}
	else
		count = get_safe_aux(t, op);
	return (count);
}
