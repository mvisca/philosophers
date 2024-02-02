/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conditions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvisca-g <mvisca-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 15:34:44 by mvisca            #+#    #+#             */
/*   Updated: 2024/02/02 19:36:44 by mvisca-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	p_dead(t_philo *p, t_table *t)
{
	long long	waiting;

	waiting = (getlong(t, NOW, 0) - getlong(t, P_LAST_MEAL, p->chair));
	if (p_hungry(p, t) && waiting >= (long long) getint(t, TIME_DIE, 0))
	{
		philo_die(p);
		return (1);
	}
	return (0);
}

int	p_hungry(t_philo *p, t_table *t)
{
	if (getint(t, P_MEAL_COUNT, p->chair) < getint(t, MAX_MEALS, 0))
		return (1);
	return (0);
}

int	pt_dead(t_table *t)
{
	if (getint(t, COUNT_DEAD, 0) != 0)
		return (1);
	return (0);
}

int	pt_hungry(t_table *t)
{
	if (getint(t, COUNT_HUNGRY, 0) > 0)
		return (1);
	return (0);
}
