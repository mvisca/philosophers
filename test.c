#include <stdio.h>
#include <pthread.h>

typedef struct s_comu
{
	int				count;
	pthread_mutex_t	mutex;
} t_comu;

void	*routine(void *arg)
{
	int		i;
	t_comu	*comu;

	comu = (t_comu *) arg;
	i = -1;
	while (++i < 1000000)
	{
		pthread_mutex_lock(&comu->mutex);
			comu->count++;
		pthread_mutex_unlock(&comu->mutex);
	}
}

int main(int ac, char *av[])
{
	t_comu		comu;
	pthread_t	p1, p2, p3, p4;

	comu.count = 0;
	pthread_mutex_init(&comu.mutex, NULL);
	if (pthread_create(&p4, NULL, &routine, &comu) != 0)
		return (4);
	if (pthread_create(&p3, NULL, &routine, &comu) != 0)
		return (3);
	if (pthread_create(&p2, NULL, &routine, &comu) != 0)
		return (2);
	if (pthread_create(&p1, NULL, &routine, &comu) != 0)
		return (1);
	if (pthread_join(p4, NULL) != 0)
		return (8);
	if (pthread_join(p3, NULL) != 0)
		return (7);
	if (pthread_join(p2, NULL) != 0)
		return (6);
	if (pthread_join(p1, NULL) != 0)
		return (5);
	printf ("cont = %d", comu.count);
	pthread_mutex_destroy(&comu.mutex);
}
