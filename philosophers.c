#include "philosophers.h"

int	main(int ac, char **av)
{
	t_gym	gym;
	
	if (gym_init(&gym, ac, av))
		return (1);
	debug_struct(&gym);


}
