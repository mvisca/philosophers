/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvisca <mvisca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 17:22:25 by mvisca            #+#    #+#             */
/*   Updated: 2024/01/28 12:43:21 by mvisca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

static int	take_forks(t_philo *philo)
{
	if (philo->chair % 2 != 0)
	{
		printf("EN TAKE FORKS ODD p\n");

		pthread_mutex_lock(&philo->fork_l);
		print_fork(philo);
		if (&philo->fork_l == philo->fork_r)
		{
			ft_usleep((int) get_safe(philo->t, TIME_DIE, 0), philo->t);
			printf("EN TAKE FORKS 1 p\n");
			return (1);
		}	
		pthread_mutex_lock(philo->fork_r);
		print_fork(philo);
	}
	else
	{
		printf("EN TAKE FORKS EVEN p\n");

		pthread_mutex_lock(philo->fork_r);
		print_fork(philo);
		pthread_mutex_lock(&philo->fork_l);
		print_fork(philo);
	}
	printf("sale de forks %d\n", philo->chair);
	return (0);
}

static int	philo_sleep_think(t_philo *philo)
{
		print_sleep(philo);
		ft_usleep((int) get_safe(philo->t, TIME_SLEEP, 0), philo->t);
		if (get_safe(philo->t, COUNT_DEAD, 0) != 0)
			return (1);
		print_think(philo);
	return (0);
}

static int	philo_eat(t_philo *philo)
{
	printf("Inicio philo_eat %d\n", philo->chair);

	if (philo->meals_count >= (int) get_safe(philo->t, MAX_MEALS, 0))
	{
		printf("\tSatisfecho de antes %d\n", philo->chair);
		pthread_mutex_lock(&philo->t->mtx_die);
		philo->last_meal = time_now(philo->t);
		pthread_mutex_unlock(&philo->t->mtx_die);
		return (1);
	}
	if (take_forks(philo))
	{
		printf("\tse va de forks %d\n", philo->chair);
		pthread_mutex_unlock(&philo->fork_l);
		pthread_mutex_unlock(philo->fork_r);
		return (1);
	}
	philo->last_meal = time_now(philo->t);
	ft_usleep((int) get_safe(philo->t, TIME_EAT, 0), philo->t);
	printf("\tcomiendo %d\n", philo->chair);
	printf("\tcomió %d\n", philo->chair);
	print_eat(philo);
	philo->meals_count += 1;
	pthread_mutex_unlock(&philo->fork_l);
	pthread_mutex_unlock(philo->fork_r);
	if (philo->meals_count >= (int) get_safe(philo->t, MAX_MEALS, 0))
	{
		printf("\tse llenó %d\n", philo->chair);
		pthread_mutex_lock(&philo->t->mtx_hungry);
		philo->t->hungry_count -= 1;
		pthread_mutex_unlock(&philo->t->mtx_hungry);
		return (1);
	}
	printf("\t seguira comiendo %d\n", philo->chair);

	return (0);
}

int	philo_die(t_philo *philo)
{
	pthread_mutex_lock(&philo->t->mtx_dead);
	philo->t->dead_count += 1;
	pthread_mutex_unlock(&philo->t->mtx_dead);
	print_die(philo);
	return (get_safe(philo->t, COUNT_DEAD, 0));
}

void	*philo_life(void *arg)
{
	t_philo	*philo;
	t_table	*t;


	philo = (t_philo *)arg;
	t = philo->t;
	while (get_safe(t, COUNT_HUNGRY, 0) != 0 \
	&& get_safe(t, COUNT_DEAD, 0) == 0)
	{
		printf("life en bucle %d\n", philo->chair); 

		if (philo_eat(philo))
			break ;
		if (get_safe(t, P_MEAL_COUNT, philo->chair) >= get_safe(t, MAX_MEALS, 0) \
		&& get_safe(t, COUNT_CHAIRS, 0) != 0)
			break ;
		philo_sleep_think(philo);
	}
	printf("\tphilo %d\n", philo->chair);
	printf("\thungry %lld y dead %lld\n", get_safe(t, COUNT_CHAIRS, 0), get_safe(t, COUNT_CHAIRS, 0));
	printf("\ta la espera\n");

	pthread_mutex_lock(&t->mtx_end);
	pthread_mutex_unlock(&t->mtx_end);
	return (NULL);
}
