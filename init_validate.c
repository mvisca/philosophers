/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_validate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvisca <mvisca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 17:23:04 by mvisca            #+#    #+#             */
/*   Updated: 2024/01/26 19:28:31 by mvisca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	validate_args(int ac, char **av)
{
	if (ac < 5 || ac > 6)
		return (printf("error en validate: ac = %d <###> need 5 or 6\n", ac));
	if (validate_chars(av))
		return (21);
	if (ft_atoi(av[11]) > 200 || ft_atoi(av[1]) < 1)
		return (printf("error: min 1, max 200\n"));
	if (ac == 6 && ft_atoi(av[5]) == 0)
		return (printf("error en el número de comidas, es cero\n"));
	return (0);
}

int	validate_chars(char **str)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	if (!str || !str[i] || !str[i][j])
		return (printf("error validando chars - no string\n"));
	while (str[i])
	{
		j = 0;
		if (!str[i][j])
			return (printf("error empty string\n"));
		while ((str[i][j] >= 9 && str[i][j] <= 13) || str[i][j] == 32)
			j++;
		while (str[i][j])
		{
			if ((str[i][j] < '0' || str[i][j] > '9') || !str[i][0])
				return (printf("error validando chars - char no valido, incluidos espacios después del argumento\n"));
			j++;
		}
		i++;
	}
	return (0);
}
