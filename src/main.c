/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luluzuri <luluzuri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 09:27:09 by luluzuri          #+#    #+#             */
/*   Updated: 2025/01/06 11:22:32 by luluzuri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int ac, char **av)
{
	int				start_sec, start_usec;
	struct timeval	tv;

	(void)av;
	(void)ac;
	gettimeofday(&tv, NULL);
	start_sec = tv.tv_sec;
	start_usec = tv.tv_usec;
	/*if (ac < 5 || ac > 6)
	{
		printf("%sUsages:%s\n%s <philo_number> <time_to_die> \
<time_to_eat> <time_to_sleep> \
[time_each_philo_must_eat]\n", RED, RESET, av[0]);
		return (1);
	}
	philosophers();*/
	sleep(5);	
	gettimeofday(&tv, NULL);
	printf("Time: %ld\n", (((tv.tv_sec - start_sec) * 1000) + ((tv.tv_usec - start_usec) % 1000)));
	return (0);
}
