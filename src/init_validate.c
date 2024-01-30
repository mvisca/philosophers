/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_validate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvisca <mvisca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 17:23:04 by mvisca            #+#    #+#             */
/*   Updated: 2024/01/30 16:05:05 by mvisca-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	validate_args(int ac, char **av)
{
	if (ac < 5 || ac > 6)
		return (write(2, "Error: argc must be 5 or 6\n", 27));
	if (validate_chars(av))
		return (21);
	if (ft_atoi(av[11]) > 200 || ft_atoi(av[1]) < 1)
		return (write(2, "Error: min 1, max 200\n", 22));
	if (ac == 6 && ft_atoi(av[5]) == 0)
		return (write(2, "Error: meals number is 0\n", 25));
	return (0);
}

int	validate_chars(char **str)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	if (!str || !str[i] || !str[i][j])
		return (write(2, "Error: invalid chars or empty string\n", 37));
	while (str[i])
	{
		j = 0;
		if (!str[i][j])
			return (write(2, "Error: empty string\n", 20));
		while ((str[i][j] >= 9 && str[i][j] <= 13) || str[i][j] == 32)
			j++;
		while (str[i][j])
		{
			if ((str[i][j] < '0' || str[i][j] > '9') || !str[i][0])
				return (write(2, "Error: char no valido en argv\n", 31));
			j++;
		}
		i++;
	}
	return (0);
}
