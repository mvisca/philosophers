/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_split.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvisca <mvisca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 09:57:56 by mvisca            #+#    #+#             */
/*   Updated: 2023/10/29 17:34:58 by mvisca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static int  get_word_count(char *str, char c)
{
	int	integers[integers_array_len];

	integers[i] = 0;
	integers[words] = 0;
	while (str && str[integers[i]])
	{
		if (ft_is_start(str, c, integers[i]))
			integers[words]++;
		integers[i]++;
	}
	// printf("integers[i] al final = %d\n", integers[i]);
	// printf("Word words %d\n", integers[words]);
	return (integers[words]);
}

static char *ft_substr(char *str, int start, int end)
{
	char	*res;
	int		j;

	res = (char *)malloc(end - start + 2);
	if (!res)
		error_exit("Malloc error en ft_substr", 9);
	j = 0;
	while (j < end - start + 1)
	{
		res[j] = str[start + j];
		j++;
	}
	res[j] = 0;
	return (res);
}

static char **do_split(char **res, char *str, char c)
{
	int	integers[integers_array_len];

	integers[i] = 0;
	integers[k] = 0;
	while (str[integers[i]])
	{
		if (ft_is_start(str, c, integers[i]))
			integers[start] = integers[i];
		if (ft_is_end(str, c, integers[i]))
		{
			integers[end] = integers[i];
			res[integers[k]] = ft_substr(str, integers[start], integers[end]);
			if (!res[integers[k]])
				error_exit("Malloc error en split", 7);
			integers[k]++;
			res[integers[k]] = NULL;
		}
		integers[i]++;
	}
	return (res);
}

char **ft_split(char *str, char c)
{
	char	**res;
	int		integers[integers_array_len];

	if (!str || !str[0])
		return (NULL);
	integers[words] = get_word_count(str, c) + 1;
	res = (char **) malloc (sizeof(char *) * integers[words] + 1);
	if (!res)
		error_exit("Malloc error en split", 6);
	integers[i] = 0;
	while (str[integers[i]])
	{
		if (ft_is_start(str, c, integers[i]))
			integers[start] = integers[i];
		if (ft_is_end(str, c, integers[i]))
			integers[end] = integers[i];
		integers[i]++;
	}
	res = do_split(res, str, c);
	return (res);
}

/*
int	main(int ac, char **av)
{
	char	**res;
	char	*demo;
	int		integers[integers_array_len];

	if (ac != 2)
		return (1);
	demo = av[1];
	printf("%s\n", demo);
	integers[c] = ' ';
	res = ft_split(demo, integers[c]);
	integers[i] = 0;
	printf("START\n");
	
	// while (res && res[integers[i]])
	// {
	// 	printf ("%s\n", res[integers[i]]);
	// 	integers[i]++;
	// }	

	ft_clean_tab(res);
	printf("END\n");
	return (0);
}

*/

/*
int main(void)
{
	char *counthis = "      i hola que tal     muy bien   ";
	printf ("num words = %d", get_word_count(counthis, ' '));
	return 1;
}
*/