/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvisca <mvisca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 17:22:25 by mvisca            #+#    #+#             */
/*   Updated: 2024/01/25 16:44:20 by mvisca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

int	dead_philo(t_philo *philo)
{
	print_die(philo);
	pthread_mutex_lock(&philo->t->mtx_dead);
	philo->t->dead_count += 1;
	pthread_mutex_unlock(&philo->t->mtx_dead);
	return (get_safe(philo->t, DEAD));
}

void	*philo_life(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	printf("antes de life cyle %d\n", philo->chair);
	while (!get_safe(philo->t, DEAD) && get_safe(philo->t, HUNGRY) != 0)
	{
		if (philo->chair == 1)
		{
			printf(">> Get safe DEAD %d\n", (int)get_safe(philo->t, DEAD));
			printf(">> Get safe HUNGRY %d\n", (int)get_safe(philo->t, HUNGRY));
		}
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
