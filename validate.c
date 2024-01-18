/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvisca <mvisca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 17:23:04 by mvisca            #+#    #+#             */
/*   Updated: 2024/01/18 15:36:16 by mvisca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_bool	validate_args(int ac, char **av)
{
	if (ac < 5 || ac > 6)
		return (!print_argserror());
	if (!validate_chars(av))
		return (!print_charerror());
	if (ft_atoi(av[1]) > 200 || ft_atoi(av[1]) < 1)
		return (!print_maxerror());
	if (ac == 6 && ft_atoi(av[5]) == 0)
		return (!print_maxerror());
	return (true_e);
}

t_bool	validate_chars(char  **str)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	if (!str || !str[i] || !str[i][j])
		return (false_e);
	while (str[i])
	{
		j = 0;
		while ((str[i][j] >= 9 && str[i][j] <= 13) || str[i][j] == 32)
			j++;
		while (str[i][j])
		{
			if ((str[i][j] < '0' || str[i][j] > '9') || !str[i][0])
				return (false_e);
			j++;
		}
		i++;
	}
	return (true_e);
}

t_bool	check_philo(t_philo *philo)
{
	return (is_alive(philo) && !is_satisfied(philo));
}

t_bool	is_alive(t_philo *philo)
{
	pthread_mutex_lock(&philo->table->stop_run);
	if (!philo->table->run)
	{
		pthread_mutex_unlock(&philo->table->stop_run);
		return (false_e);
	}
	if (time_now() - philo->last_meal >= philo->table->time_die)
	{
		philo->table->run = false_e;
		pthread_mutex_unlock(&philo->table->stop_run);
		return (false_e);
	}
	pthread_mutex_unlock(&philo->table->stop_run);
	return (true_e);
}

t_bool	is_satisfied(t_philo *philo)
{
	pthread_mutex_lock(&philo->table->count);
	if (philo->meals_count == philo->table->total_meals)
	{
		pthread_mutex_unlock(&philo->table->count);
		return (true_e);
	}
	pthread_mutex_unlock(&philo->table->count);
	return (false_e);
}
