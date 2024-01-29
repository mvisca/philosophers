/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvisca <mvisca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 17:22:25 by mvisca            #+#    #+#             */
/*   Updated: 2024/01/30 00:37:05 by mvisca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

static int	philo_sleep(t_philo *philo)
{
		print_sleep(philo);
		ft_usleep(getint(philo->t, TIME_SLEEP, 0), philo->t);
	return (0);
}

static int	take_forks(t_philo *philo)
{
	if (philo->chair % 2 == 0)
	{
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

static int	philo_eat(t_philo *philo)
{
	update_last_meal(philo);
	print_eat(philo);
	ft_usleep(getint(philo->t, TIME_EAT, 0), philo->t);
	pthread_mutex_unlock(philo->fork_r);
	pthread_mutex_unlock(&philo->fork_l);
	if (p_hungry(philo, philo->t))
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
	if (!pt_dead(philo->t))
	{
		pthread_mutex_lock(&philo->t->mtx_dead);
		philo->t->dead_count += 1;
		pthread_mutex_unlock(&philo->t->mtx_dead);	
		ft_usleep(200, philo->t);
		print_die(philo);
	}
	return (getint(philo->t, COUNT_DEAD, 0));
}

void	*philo_life(void *arg)
{
	t_philo	*philo;
	t_table	*t;

	philo = (t_philo *)arg;
	t = philo->t;
	if (getint(t, COUNT_CHAIRS, 0) == 1)
	{
		print_fork(philo);
		ft_usleep(getint(philo->t, TIME_DIE, 0), philo->t);
		philo_die(philo);
	}
	else
	{
		while (!pt_dead(t) && p_hungry(philo, t))
		{
			take_forks(philo);
			if (!p_dead(philo, t))
				philo_eat(philo);
			else
			{
				pthread_mutex_unlock(philo->fork_r);
				pthread_mutex_unlock(&philo->fork_l);
			}
			if (!p_dead(philo, t) && p_hungry(philo, t))
				philo_sleep(philo);
			if (!p_dead(philo, t) && p_hungry(philo, t))
				print_think(philo);
		}
	}
	pthread_mutex_lock(&t->mtx_end);
	ft_usleep(10, t);
	pthread_mutex_unlock(&t->mtx_end);
	return (NULL);
}
