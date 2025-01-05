/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luluzuri <luluzuri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 09:27:09 by luluzuri          #+#    #+#             */
/*   Updated: 2025/01/05 10:00:59 by luluzuri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int ac, char **av)
{
	(void)av;
	if (ac < 5 || ac > 6)
	{
		printf("%sUsages:%s\n%s <philo_number> <time_to_die> \
<time_to_eat> <time_to_sleep> \
[time_each_philo_must_eat]\n", RED, RESET, av[0]);
		return (1);
	}
	philosophers();
	return (0);
}
