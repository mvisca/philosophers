#include "philo.h"

int	main(int ac, char **av)
{
	t_table	table;

	if (init_table(ac, av, &table) && init_philos(&table))
		table.time_zero = time_now();
	else
		return (1);
	join_philos(&table);
	print_structs(&table);
	free_all(&table);
	return (0);
}
