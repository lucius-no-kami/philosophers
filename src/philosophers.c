/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luluzuri <luluzuri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 09:27:16 by luluzuri          #+#    #+#             */
/*   Updated: 2025/03/09 17:50:52 by luluzuri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static int	check_entries(char **entries)
{
	int	i;
	int	j;

	i = 0;
	while (entries[++i])
	{
		j = -1;
		while (entries[i][++j])
			if (entries[i][j] < '0' || entries[i][j] > '9')
				return (1);
	}
	if (ft_atoi(entries[1]) > 200)
		return (2);
	return (0);
}

static void	init_main_args(t_philo *tab, char **entries, int i, int nphilo)
{
	tab[i].time_to_die = ft_atoi(entries[2]);
	tab[i].time_to_eat = ft_atoi(entries[3]);
	tab[i].time_to_die = ft_atoi(entries[4]);
	tab[i].num_of_philos = nphilo;
	if (entries[5])
		tab[i].num_times_to_eat = ft_atoi(entries[5]);
}

static void	init_philos(t_philo *tab, char **entries)
{
	int	i;
	int	nphilo;

	i = 0;
	nphilo = ft_atoi(entries[1]);
	while (i < nphilo)
	{
		pthread_create(tab[i].thread, NULL, incoming, NULL);
		tab[i].id = i;
		tab[i].eating = 0;
		tab[i].meals_eaten = 0;
		tab[i].last_meal = 0;
		int_main_args(tab, entries, i, nphilo);
		tab[i].start_time = 0;
		tab[i].dead = 0;
	}
}

int	philosophers(char **entries)
{
	int		ret;
	t_philo	tab[200];

	ret = check_entries(entries);
	if (ret == 1)
	{
		printf("Error: all entries must be numbers\n");
		return (ret);
	}
	else if (ret == 2)
	{
		printf("%sError%s: numbers of philosophers must \
be contained between 1 and 200\n", RED, RESET);
		return (ret);
	}
	init_philos(&tab);
	return (0);
}
