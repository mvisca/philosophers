#include <philo.h>

t_bool	is_satisfied(t_philo *philo)
{
	if (philo->meals_count >= philo->table->total_meals)
		return (true);
	return (false);
}

t_bool	is_alive(t_philo *philo)
{
	if (time_now() - philo->last_meal < philo->table->time_die)
		return (true);
	philo->is_alive = false;
	print_die(philo);
	return (false);
}

void	eat(t_philo *philo)
{
	if (philo->chair_num % 2 == 0)
		usleep(10);
	if (is_alive(philo))
	{
		pthread_mutex_lock(&philo->left_f);
		print_fork(philo);
		pthread_mutex_lock(philo->right_f);
		print_fork(philo);
		philo->last_meal = time_now();
		pthread_mutex_unlock(&philo->left_f);
		pthread_mutex_unlock(philo->right_f);
		print_eat(philo);
	}
}

static void	toggle_tablerun(t_table *table)
{
	if (pthread_mutex_lock(&table->stop_run) != 0)
	{
		free_all(table);
		print_mutexinierror(table);
		return ;
	}
}

void	*philo_life(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->last_meal < 0)
	{
		while (!philo->table->time_zero)
			usleep(5);
		philo->last_meal = philo->table->time_zero;
	}
	while (is_alive(philo) && !is_satisfied(philo))
	{
		eat(philo);
		if (is_alive(philo) && print_sleep(philo))
			ft_usleep(philo->table->time_sleep);
		if (is_alive(philo))
			print_think(philo);
		else
			toggle_tablerun(philo->table);
	}
	return (NULL);
}
