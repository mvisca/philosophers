#include <philo.h>

t_bool	is_satisfied(t_philo *philo)
{
	printf("HERE SAT\n");
	if (philo->meals_count == philo->table->total_meals)
	{
		printf("HERE SAT 2\n");
		philo->is_satisfied = true_e;
		pthread_mutex_lock(&philo->table->count);
		philo->table->philos_done++;
		pthread_mutex_unlock(&philo->table->count);
		return (true_e);
	}
	printf("HERE SAT 3\n");
	return (false_e);
}

t_bool	is_alive(t_philo *philo)
{
	printf("HERE LIVE\n");
	if (time_now() - philo->last_meal < philo->table->time_die)
		return (true_e);
	stop_tablerun(philo->table);
	philo->is_alive = false_e;
	print_die(philo);
	return (false_e);
}

void	eat(t_philo *philo)
{
	if (philo->chair_num % 2 == 0)
		ft_usleep(500);
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
		philo->meals_count++;
	}
}

void	stop_tablerun(t_table *table)
{
	pthread_mutex_lock(&table->stop_run);
	table->run = false_e;
	pthread_mutex_unlock(&table->stop_run);
}

void	*philo_life(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (!philo->table->time_zero)
		usleep(50);
	philo->last_meal = philo->table->time_zero;

	printf("HERE 2\n");
	while (philo->table->run && is_alive(philo) && !is_satisfied(philo))
	{
		printf("HERE 3\n");
		eat(philo);
		if (is_alive(philo) && print_sleep(philo))
			ft_usleep(philo->table->time_sleep);
		if (is_alive(philo))
			print_think(philo);
		else
			stop_tablerun(philo->table);
	}
	while (philo->table->philos_done >= philo->table->philos_n)
	{
		ft_usleep(100);
	}
	return (NULL);
}
