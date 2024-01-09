#include "philo.h"

t_bool	print_fork(t_philo *philo)
{
	pthread_mutex_lock(&philo->table->print);
	printf("%lld %d has taken a fork\n", time_now(), philo->chair_num);
	pthread_mutex_unlock(&philo->table->print);
	return (true_e);
}

t_bool	print_eat(t_philo *philo)
{	
	pthread_mutex_lock(&philo->table->print);
	printf("%lld %d is eating\n", philo->last_meal, philo->chair_num);
	pthread_mutex_unlock(&philo->table->print);
	return (true_e);
}

t_bool	print_sleep(t_philo *philo)
{
	pthread_mutex_lock(&philo->table->print);
	printf("%lld %d is sleeping\n", time_now(), philo->chair_num);
	pthread_mutex_unlock(&philo->table->print);
	return (true_e);
}

t_bool	print_think(t_philo *philo)
{
	pthread_mutex_lock(&philo->table->print);
	printf("%lld %d is thinking\n", time_now(), philo->chair_num);
	pthread_mutex_unlock(&philo->table->print);
	return (true_e);
}

t_bool	print_die(t_philo *philo)
{
	pthread_mutex_lock(&philo->table->print);
	printf("%lld %d died\n", time_now(), philo->chair_num);
	pthread_mutex_unlock(&philo->table->print);
	return (true_e);
}
