#include "philo.h"

t_bool	validate_args(int ac, char **av)
{
	if (ac < 5 || ac > 6)
	{
		print_argserror();
		return (false_e);
	}
	if (!validate_chars(av))
	{
		print_charerror();
		return (false_e);
	}
	printf("HERE %d\n",ft_atoi(av[1]));
	if (ft_atoi(av[1]) > 200 || ft_atoi(av[1]) < 1)
	{
		printf("validate args\n");
		print_maxerror();
		return (false_e);
	}
	return (true_e);
}

t_bool	validate_chars(char  **str)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	if (!str || !str[i] || !str[i][j])
		return (false_e);
	while (str[i])
	{
		j = 0;
		while ((str[i][j] >= 9 && str[i][j] <= 13) || str[i][j] == 32)
			j++;
		while (str[i][j])
		{
			if ((str[i][j] < '0' || str[i][j] > '9') || !str[i][0])
				return (false_e);
			j++;
		}
		i++;
	}
	return (true_e);
}
