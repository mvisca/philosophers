#include "philosophers.h"

// Se crea el hilo y se ejecuta inmediatamente esta función
void	*gym_table(void *data)
{
	t_gym	*gym;

	gym = (t_gym *)data;
	// esta es la función que se llama cuando los filósofos están listos para comenzar el programa;
	return (0);
}

int	gym_thread_create(t_gym *gym)
{
	int				i;

	i = 0;
	while (i < gym->total_philos)
	{
		if (pthread_mutex_init(&gym->forks[i], NULL))
			error_exit("Error: mutex creation", 18);

		gym->philos[i]->philo_thread = (pthread_t *)malloc(sizeof(pthread_t));
		if (!gym->philos[i]->philo_thread)
			error_exit("Error: malloc at gym_open", 16);
	
		if (pthread_create(gym->philos[i]->philo_thread, NULL, &gym_table, NULL))
			error_exit("Error: creating thread", 17000 + i);
	
		gym->philos[i]->is_alive = 1;
		gym->philos[i]->is_done = 0;
		gym->philos[i]->last_meal = 0;
	
		i++;
	}
	gym->open_time = gym_gettime();
	return (0);
}

int	gym_thread_destroy(t_gym *gym)
{
	int	i;

	i = 0;
	while (i > gym->total_philos)
	{

		i++;
	}
}

// sets the initial time for all philos
int	gym_open(t_gym *gym)
{
	gym_thread_create(gym);
	// tengo los filósofos creados;
	gym_thread_destroy(gym);
}

int	main(int ac, char **av)
{
	t_gym	gym;

	if (gym_init(&gym, ac, av))
		return (1);
	gym_open(&gym);
	debug_struct(&gym);
	debug_print_time();
	exit (0);
}
