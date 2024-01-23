/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvisca <mvisca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 17:23:04 by mvisca            #+#    #+#             */
/*   Updated: 2024/01/23 02:28:48 by mvisca           ###   ########.fr       */
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

t_bool	is_hungry(t_philo *philo)
{
	if (philo->hungry_me && !philo->meals_due)
	{
		pthread_mutex_lock(&philo->t->use_meals);
		philo->t->hungry_count--;
		pthread_mutex_unlock(&philo->t->use_meals);
		philo->hungry_me = false_e;
	}	
	return (philo->hungry_me);
}

t_bool	is_alive(t_philo *philo)
{
	if (!philo->t->alive_all)
		return (false_e);
	pthread_mutex_lock(&philo->t->use_time);
	if (time_now() - philo->meal_last >= philo->t->die_time)
		philo->alive_me = false_e;
	pthread_mutex_unlock(&philo->t->use_time);
	return (philo->alive_me);
}

t_bool	check_philo(t_philo *philo)
{
	
	is_hungry(philo);
	is_alive(philo);
	pthread_mutex_lock(&philo->t->use_alive);
	philo->t->alive_all *= philo->alive_me;
	pthread_mutex_unlock(&philo->t->use_alive);

	return (philo->hungry_me * philo->t->alive_all);
}
