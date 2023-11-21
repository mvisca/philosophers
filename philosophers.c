/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvisca-g <mvisca-g@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 18:01:17 by mvisca-g          #+#    #+#             */
/*   Updated: 2023/11/21 20:31:27 by mvisca-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int ac, char **av)
{
	in		invalid;
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

