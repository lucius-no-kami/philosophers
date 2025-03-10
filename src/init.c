/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luluzuri <luluzuri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 14:14:04 by luluzuri          #+#    #+#             */
/*   Updated: 2025/03/10 14:24:37 by luluzuri         ###   ########.fr       */
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
	if (ft_atoi(entries[1]) > 200 && ft_atoi(entries[1]) < 1)
		return (2);
	i = 1;
	while (entries[++i])
	{
		if (ft_atoi(entries[i]) < 1)
			return (3);
	}
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

static int	init_philos(t_philo *tab, char **entries)
{
	int	i;
	int	nphilo;

	i = 0;
	nphilo = ft_atoi(entries[1]);
	while (i < nphilo)
	{
		pthread_create(tab[i].thread, NULL, life, NULL);
		tab[i].id = i;
		tab[i].eating = 0;
		tab[i].meals_eaten = 0;
		tab[i].last_meal = 0;
		int_main_args(tab, entries, i, nphilo);
		tab[i].start_time = 0;
		tab[i].dead = 0;
	}
}

static int	init_prog(t_program *prog, t_philo *tab)
{
	prog->dead_flag = 0;
	if (pthread_mutex_init(&prog->dead_lock, NULL))
		return (4);
	if (pthread_mutex_init(&prog->meal_lock, NULL))
		return (4);
	if (pthread_mutex_init(&prog->write_lock, NULL))
		return (4);
	prog->philos = tab;
	return (0);
}

int	global_init(t_program *prog, t_philo *tab, char **entries)
{
	int	ret;

	ret = check_entries(entries);
	if (ret != 0)
		return (ret);
	ret = init_prog(prog, tab);
	if (ret != 0)
		return (ret);
	ret = init_philos(tab, entries);
	if (ret != 0)
		return (ret);
	return (0);
}
