#include "philosophers.h"

// imprimir estructura

void    debug_struct(t_gym *gym)
{
	printf("gym > %s\n", gym != NULL ? "TURE" : "FALSE");
	printf("gym->philos > %s\n", gym->philos != NULL ? "TURE" : "FALSE");

	int i = 0;
	while (i < gym->total_philos)
	{
		printf("\tphilosopher number: gym->philos[%d]\n", i);
		if (gym->philos && gym->philos[i])
		{
			if (gym->philos[i]->philo_thread)
				printf("\t\tphilo_thread > %s\n", *(gym->philos[i]->philo_thread) ? "TRUE" : "FALSE");
			printf("\t\tphilo_index > %d\n", gym->philos[i]->philo_index);
			printf("\t\tmeals_to_be_done > %d\n", gym->philos[i]->meals_to_be_done);
			printf("\t\tis_alive > %s\n", gym->philos[i]->is_alive ? "Yes" : "No");
			printf("\t\tis_done > %s\n", gym->philos[i]->is_done ? "Yes" : "No");
		}
		i++;
	}
	printf("gym->meals_to_be_done > %s\n", gym->meals_to_be_done != NULL ? "TURE" : "FALSE");
	printf("gym->total_philos > %d\n", gym->total_philos);
	printf("gym->time_to_die > %lu\n", gym->time_to_die);
}
