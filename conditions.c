/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conditions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvisca <mvisca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 15:34:44 by mvisca            #+#    #+#             */
/*   Updated: 2024/01/29 15:46:39 by mvisca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	p_dead(t_philo *p, t_table *t)
{
	int	age;

	age = (int) (getlong(t, NOW, 0) - getlong(t, P_LAST_MEAL, p->chair));
	if (age >= getint(t, TIME_DIE, 0))
		return (1);
	return (0);
}

int p_hungry(t_philo *p, t_table *t)
{
	if (getint(t, P_MEAL_COUNT, p->chair) < getint(t, MAX_MEALS, 0))
		return (1);
	return (0);
}

int pt_dead(t_table *t)
{
	if (t->dead_count != 0)
		return (1);
	return (0);
}

int pt_hungry(t_table *t)
{
	if (t->hungry_count < 0)
		return (1);
	return (0);
}
