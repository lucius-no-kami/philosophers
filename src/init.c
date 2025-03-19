/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luluzuri <luluzuri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 14:14:04 by luluzuri          #+#    #+#             */
/*   Updated: 2025/03/19 14:34:54 by luluzuri         ###   ########.fr       */
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
	if (ft_atoi(entries[1]) > 200 || ft_atoi(entries[1]) < 1)
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
	tab[i].time_to_sleep = ft_atoi(entries[4]);
	tab[i].num_of_philos = nphilo;
	if (entries[5])
		tab[i].num_times_to_eat = ft_atoi(entries[5]);
	else
		tab[i].num_times_to_eat = -1;
}

static int	init_philos(t_program *prog, t_philo *tab, char **entries)
{
	int	i;
	int	nphilo;

	i = -1;
	nphilo = ft_atoi(entries[1]);
	while (++i < nphilo)
	{
		tab[i].id = i;
		tab[i].eating = 0;
		tab[i].meals_eaten = 0;
		tab[i].last_meal = 0;
		init_main_args(tab, entries, i, nphilo);
		tab[i].start_time = 0;
		tab[i].dead = &prog->dead_flag;
		tab[i].write_lock = &prog->write_lock;
		tab[i].dead_lock = &prog->dead_lock;
		tab[i].meal_lock = &prog->meal_lock;
	}
	return (0);
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

int	global_init(t_program *prog, t_philo *tab, \
	pthread_mutex_t *forks, char **entries)
{
	int	ret;
	int	i;

	ret = check_entries(entries);
	i = -1;
	if (ret != 0)
		return (ret);
	ret = init_prog(prog, tab);
	if (ret != 0)
		return (ret);
	ret = init_philos(prog, tab, entries);
	if (ret != 0)
		return (ret);
	while (++i < tab[0].num_of_philos)
	{
		pthread_mutex_init(fork[i], NULL),
	}
	return (0);
}
