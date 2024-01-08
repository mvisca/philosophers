#include <philo.h>

t_bool	join_philos(t_table *table)
{
	int	n;

	n = 0;
	while (n < table->philos_n)
	{
		if (pthread_join(table->philos[n].p_thread, NULL) != 0)
		{
			printf("Error in pthread_join at index %d\n", n);
			free_all(table);
			return (false_e) ;
		}
		n++;
	}
	return (true_e);
}
