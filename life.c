/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvisca <mvisca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 17:22:25 by mvisca            #+#    #+#             */
/*   Updated: 2024/01/24 18:46:45 by mvisca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

// static void	wait_others(t_philo *philo)
// {
// 	long long	time;

// 	pthread_mutex_lock(&philo->t->mtx_time);
// 	time = philo->t->start_time;
// 	pthread_mutex_unlock(&philo->t->mtx_time);
// 	while (time == 0)
// 	{
// 		pthread_mutex_lock(&philo->t->mtx_time);
// 		time = philo->t->start_time;
// 		pthread_mutex_unlock(&philo->t->mtx_time);
// 		ft_usleep(20, philo->t);
// 	}
// 	printf("out wait life con philo = %d\n", philo->chair);
// }

int	dead_philo(t_philo *philo)
{
	if (get_time(philo->t) - philo->last_meal >= philo->t->die_time)
	{
		print_die(philo);
		philo->t->dead_count += 1;
	}
	return (philo->t->dead_count);
}

void	*philo_life(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	printf("antes de life cyle %d\n", philo->chair);
	while (!get_safe(philo->t, DEAD) && get_safe(philo->t, HUNGRY) != 0)
	{
		printf("en bucle life cyle %d\n", philo->chair);
		if (!philo_eat(philo))
		{
			print_sleep(philo);
			ft_usleep(get_safe(philo->t, SLEEP), philo->t);
			if (!get_safe(philo->t, DEAD) && get_safe(philo->t, HUNGRY) != 0)
				print_think(philo);
		}
	}
	printf("después de life cyle %d\n", philo->chair);
	return (NULL);
}

//	wait_others(philo);
//	printf("out wait philo_life for philo %d\n", philo->chair);
//	pthread_mutex_lock(&philo->t->mtx_time);
//	philo->last_meal = philo->t->start_time;
//	pthread_mutex_unlock(&philo->t->mtx_time);
