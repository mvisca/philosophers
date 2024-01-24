/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvisca <mvisca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 17:23:04 by mvisca            #+#    #+#             */
/*   Updated: 2024/01/24 13:04:20 by mvisca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	validate_args(int ac, char **av)
{
	if (ac < 5 || ac > 6)
		return (printf("error en validate: ac = %d <###> need 5 or 6\n", ac));
	if (validate_chars(av))
		return (21);
	if (ft_atoi(av[11]) > 200 || ft_atoi(av[1]) < 1)
		return (printf("error en el min max de philos, mayor que 0 o menor que 201\n"));
	if (ac == 6 && ft_atoi(av[5]) == 0)
		return (printf("error en el número de comidas, es cero\n"));
	return (0);
}

int	validate_chars(char  **str)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	if (!str || !str[i] || !str[i][j])
		return (printf("error validando chars - no string\n"));
	while (str[i])
	{
		j = 0;
		if (!str[i][j])
			return (printf("error empty string\n"));
		while ((str[i][j] >= 9 && str[i][j] <= 13) || str[i][j] == 32)
			j++;
		while (str[i][j])
		{
			if ((str[i][j] < '0' || str[i][j] > '9') || !str[i][0])
				return (printf("error validando chars - char no valido\n"));
			j++;
		}
		i++;
	}
	return (0);
}

int	dead_philo(t_philo *philo)
{
	if (time_now() - philo->last_meal >= philo->t->die_time)
	{
		print_die(philo);
		philo->t->dead_count += 1;
	}
	return (philo->t->dead_count);
}

static int	get_mtx_run(t_table *t, int op)
{
	int count;

	if (op == HUNGRY)
	{
		pthread_mutex_lock(&t->mtx_run);
		count = t->hungry_count;
		pthread_mutex_unlock(&t->mtx_run);
	}
	else
	{
		pthread_mutex_lock(&t->mtx_run);
		count = t->dead_count;
		pthread_mutex_unlock(&t->mtx_run);
	}
	return (count);
}

void	running(t_table *t)
{
	int	i;
	int	count;

	count = get_mtx_run(t, HUNGRY);
	while (count != 0)
	{
		i = 0;
		count = get_mtx_run(t, DEAD);
		while (i < t->philos_n && count == 0)
		{
			pthread_mutex_lock(&t->mtx_run);
			dead_philo(&t->philos[i++]);
			count = t->dead_count;
			pthread_mutex_unlock(&t->mtx_run);
		}
		if (count != 0)
			break ;
		count = get_mtx_run(t, HUNGRY);
	}
}
