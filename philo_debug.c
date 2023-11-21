#include "philosophers.h"

// imprimir estructura

void    debug_struct(t_gym *gym)
{
	printf("gym > %s\n", gym != NULL ? "TRUE" : "FALSE");
	printf("gym->time_to_die > %lu\n", gym->time_to_die);
	printf("gym->time_to_eat > %lu\n", gym->time_to_eat);
	printf("gym->time_to_sleep > %lu\n", gym->time_to_sleep);
	printf("gym->open_time > %lu\n", gym->open_time);
	if (gym->meals_to_be_done == -1)
		printf("gym->meals_to_be_done > NONE\n");
	else
		printf("gym->meals_to_be_done > %d\n", gym->meals_to_be_done);
	printf("gym->forks > %s\n", gym->forks != NULL ? "TRUE" : "FALSE");
	printf("gym->total_philos > %d\n", gym->total_philos);
	printf("gym->philos > %s\n", gym->philos != NULL ? "TRUE" : "FALSE");
	int i = 0;
	while (i < gym->total_philos)
	{
		printf("\tphilosopher number: gym->philos[%d]\n", i);
		if (gym->philos && gym->philos[i])
		{
			if (gym->philos[i]->philo_thread)
				printf("\t\tphilo_thread > %s\n", *(gym->philos[i]->philo_thread) ? "TRUE" : "FALSE");
			printf("\t\tphilo_index > %d\n", gym->philos[i]->philo_index);
			printf("\t\tis_alive > %s\n", gym->philos[i]->is_alive ? (gym->philos[i]->is_done == -1 ? "Undefined" : "Yes") : "No");
			printf("\t\tis_done > %s\n", gym->philos[i]->is_done ? (gym->philos[i]->is_done == -1 ? "Undefined" : "Yes") : "No");
		}
		i++;
	}
}

void	debug_print_time(void)
{
	uint64_t	time;

	time = gym_gettime();
	printf("Time is = %lu", time);
}
