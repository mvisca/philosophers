#include <philosophers.h>

int clean_tab(char **tab)
{
    int i;

    i = 0;
    while (tab && tab[i])
    {
        free(tab[i]);
        i++;
    }
    if (tab)
        free(tab);
	return (0);
}

void	error_exit(char *str, int exit_code)
{
	printf ("%s\n", str);
	exit (exit_code);
}

uint64_t	ft_ato64(char *ascii)
{
	unsigned long long	n;
	char				*aux;

	n = 0;
	aux = ascii;
	while (aux && *aux)
	{
		if (*aux < '0' || *aux > '9')
			error_exit("Error: parámetros contienen no dígitos", 13);
		aux++;
	}
	while (ascii && *ascii)
		n = (n * 10) + *(ascii++) - '0';
//	printf("ato64 %llu\n", n);
	return ((uint64_t)n);
}

int	ft_atoi(char *ascii)
{
	long	n;
	char	*aux;

	n = 0;
	aux = ascii;
	while (aux && *aux)
	{
		if (*aux < '0' || *aux > '9')
			error_exit("Error: parámetros contienen no dígitos", 12);
		aux++;
	}
	while (ascii && *ascii)
		n = (n * 10) + *(ascii++) - '0';
	if (n < INT_MIN || n > INT_MAX)
		error_exit("Error: integer type overflow\n", 4);
	// printf("atoi %ld\n", n);
	return (n);
}

int	arr_len(char **tab)
{
	int	i;

	i = 0;
	while (tab && tab[i])
		i++;
	return (i);
}
