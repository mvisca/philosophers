/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvisca <mvisca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 17:22:25 by mvisca            #+#    #+#             */
/*   Updated: 2024/01/29 08:55:41 by mvisca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

static int	philo_sleep(t_philo *philo)
{
		print_sleep(philo);
		ft_usleep(getint(philo->t, TIME_SLEEP, 0), philo->t);
		print_think(philo);
	return (0);
}

static int	take_forks(t_philo *philo)
{
	if (getint(philo->t, COUNT_CHAIRS, 0) == 1)
		return (1);
	if (philo->chair % 2 == 0)
	{
		ft_usleep(100, philo->t);
		pthread_mutex_lock(&philo->fork_l);
		print_fork(philo);
		pthread_mutex_lock(philo->fork_r);
		print_fork(philo);
		return (0);
	}
	pthread_mutex_lock(philo->fork_r);
	print_fork(philo);
	pthread_mutex_lock(&philo->fork_l);
	print_fork(philo);
	return (0);
}

static int	philo_eat(t_philo *philo, t_table *t, int i)
{
	if (getint(t, P_MEAL_COUNT, i) >= getint(t, MAX_MEALS, 0))
	{
		update_last_meal(philo);
		return (1);
	}
	update_last_meal(philo);
	print_eat(philo);
	philo->meals_count += 1;
	ft_usleep(getint(philo->t, TIME_EAT, 0), philo->t);
	pthread_mutex_unlock(philo->fork_r);
	pthread_mutex_unlock(&philo->fork_l);
	if (philo->meals_count >= getint(philo->t, MAX_MEALS, 0))
	{
		pthread_mutex_lock(&philo->t->mtx_hungry);
		philo->t->hungry_count -= 1;
		pthread_mutex_unlock(&philo->t->mtx_hungry);
		return (1);
	}
	return (0);
}

int	philo_die(t_philo *philo)
{
	pthread_mutex_lock(&philo->t->mtx_dead);
	philo->t->dead_count += 1;
	pthread_mutex_unlock(&philo->t->mtx_dead);
	ft_usleep(200, philo->t);
	print_die(philo);
	return (getint(philo->t, COUNT_DEAD, 0));
}

void	*philo_life(void *arg)
{
	t_philo	*philo;
	t_table	*t;

	philo = (t_philo *)arg;
	t = philo->t;
	while (getint(t, COUNT_HUNGRY, 0) && !getint(t, COUNT_DEAD, 0))
	{
		printf("OUT condition %s\n", (getint(t, P_MEAL_COUNT, philo->chair) < getint(t, MAX_MEALS, 0)) ? "TRUE" : "FALSE");
		printf("OUT Meal Count get & struct %d y %d\n", (getint(t, P_MEAL_COUNT, philo->chair)), philo->meals_count);
		printf("OUT MAx Meals %d\n", (getint(t, MAX_MEALS, 0)));

		if (getint(t, P_MEAL_COUNT, philo->chair) < getint(t, MAX_MEALS, 0))
		{
			printf("OUT %d\n", philo->chair);
			if (take_forks(philo) != 0)
			{
				print_fork(philo);
				ft_usleep(getint(philo->t, TIME_DIE, 0), philo->t);
				philo_die(philo);
				return (NULL);
			}
			if (getint(t, COUNT_HUNGRY, 0) && !getint(t, COUNT_DEAD, 0) && \
			getint(t, P_MEAL_COUNT, philo->chair) < getint(t, MAX_MEALS, 0))
				philo_eat(philo, philo->t, philo->chair);
			if (getint(t, COUNT_HUNGRY, 0) && !getint(t, COUNT_DEAD, 0) && \
			getint(t, P_MEAL_COUNT, philo->chair) < getint(t, MAX_MEALS, 0))
				philo_sleep(philo);
		}
	}
	pthread_mutex_lock(&t->mtx_end);
	ft_usleep(10, t);
	pthread_mutex_unlock(&t->mtx_end);
	return (NULL);
}
