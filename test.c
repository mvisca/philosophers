#include <stdio.h>
#include <limits.h>

static int	ft_atoi(char *str)
{
	long long	result;
	int			i;

	result = 0;
	i = 0;
	while (str && ((str[i] >= 9 && str[i] <= 13) || str[i] == 32))
		i++;
	while (str && str[i])
	{
		result = (result * 10) + str[i] - '0';
		i++;
	}
	if (result < INT_MIN || result > INT_MAX)
		return (-1);
	return (result);
}

static int	prev_n(int total, int n)
{
		int i = 0;
		while (i < total)
		{
			printf("%d ", i);
			i++;
		}
		printf("\n");

		printf("total = %d\n", total);
		printf("actual = %d\n", n);
		printf("anterior = %d\n", (n + total - 1) % total);
		return (0);
}
int main(int ac, char **av)
{

	int	total = ft_atoi(av[1]);
	int n = ft_atoi(av[2]);
	prev_n(total, n);
    return (0);
}
