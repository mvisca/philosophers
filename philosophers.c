/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvisca-g <mvisca-g@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 18:01:17 by mvisca-g          #+#    #+#             */
/*   Updated: 2023/11/21 19:02:31 by mvisca-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

// Se crea el hilo y se ejecuta inmediatamente esta función
void	*gym_table(void *data)
{
	t_gym	*gym;

	gym = (t_gym *)data;
	// esta es la función que se llama cuando los filósofos están listos para comenzar el programa;
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
	return (0);
}

// sets the initial time for all philos
int	gym_execute(t_gym *gym)
{
	gym_forks_create(gym); // tenedores creados;
	gym_philos_create(gym);	// filósofos creados;

	gym_thread_destroy(gym);
	return (0);
}

int	main(int ac, char **av)
{
	int		invalid;
	t_gym	gym;

	invalid = gym_init(&gym, ac, av);
	if (invalid)
		return (1);
	gym_execute(&gym);
	
	// for debug only
	debug_struct(&gym);
	debug_print_time();
	exit (33);
	return (0);
}

