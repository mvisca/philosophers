#include "philo.h"

void	print_structs(t_table *table)
{
	pthread_mutex_lock(&table->print);
	printf("Table %p\n", table);
	printf("Table->philos_n %d\n", table->philos_n);
	int i = 0;
	while (i < table->philos_n)
	{
		printf("---- i = %d", i);
		printf("\tTable->philo->chair_num %d\n", table->philos[i].chair_num);
		printf("\tPhilo->p_thread %p\n", &table->philos[i].p_thread);
		printf("\tPhilo->last_meal %lld\n", table->philos[i].last_meal);
		printf("\tPhilo->meals_count %d\n", table->philos[i].meals_count);
		printf("\tPhilo->left_f %p\n", &table->philos[i].left_f);
		printf("\tPhilo->right_f %p\n", table->philos[i].right_f);
		printf("\tPhilo->table %p\n", table->philos[i].table);
		i++;
	}
	printf("Table->time zero %lld\n", table->time_zero);
	printf("Table->time die %d\n", table->time_die);
	printf("Table->time eat %d\n", table->time_eat);
	printf("Table->time sleep %d\n", table->time_sleep);
	printf("Table->total meal %d\n", table->total_meals);
	printf("Table->philos done %d\n", table->philos_done);
	printf("Table->run %s\n", table->run ? "ture" : "false");
	printf("Table->count mutex %p\n", &table->count);
	printf("Table->print mutex %p\n", &table->print);
	printf("Table->stop_run mutex %p\n", &table->stop_run);
	printf("Table->time mutex %p\n", &table->time);
	pthread_mutex_unlock(&table->print);
}
