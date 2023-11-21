#include "philosophers.h"

uint64_t	gym_gettime()
{
	struct timeval	current_time;
	uint64_t		msec_time;

	gettimeofday(&current_time, NULL);
	msec_time = (uint64_t)current_time.tv_sec * 1000000 + current_time.tv_usec;
	return (msec_time);
}
