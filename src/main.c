/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luluzuri <luluzuri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 09:27:09 by luluzuri          #+#    #+#             */
/*   Updated: 2025/03/19 14:25:36 by luluzuri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	print_error(int cerror)
{
	printf("%sError%s: ", RED, RESET);
	if (cerror == 1)
		printf("%s", NUM_ERROR);
	else if (cerror == 2)
		printf("%s", PHILO_ERROR);
	else if (cerror == 3)
		printf("%s", ENTRIES_ERROR);
	printf("\n");
}

int	main(int ac, char **av)
{
	int				ret;
	t_program		prog;
	t_philo			philos[200];
	pthread_mutex_t	forks[200];

	if (ac < 5 || ac > 6)
	{
		printf("%sUsages:%s\n%s %s", RED, RESET, av[0], USAGE);
		return (1);
	}
	ret = global_init(&prog, philos, forks, av);
	if (ret != 0)
	{
		print_error(ret);
		return (ret);
	}
/*	dinner(&prog); */
	clean(&prog);
	return (0);
}

/* 
	int				start_sec, start_usec;
	struct timeval	tv;

	(void)av;
	(void)ac;
	gettimeofday(&tv, NULL);
	start_sec = tv.tv_sec;
	start_usec = tv.tv_usec;
*/
	
// ((tv.tv_sec - start_sec) * 1000) + ((tv.tv_usec - start_usec) % 1000) -> time in milisecondes