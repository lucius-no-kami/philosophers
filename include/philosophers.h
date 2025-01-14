/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luluzuri <luluzuri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 09:26:53 by luluzuri          #+#    #+#             */
/*   Updated: 2025/01/14 08:13:37 by luluzuri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

/* colors */
# define RED			"\033[0;31m"
# define WHITE			"\x1B[37m"
# define BLACK          "\033[0;30m"
# define GREEN          "\033[0;32m"
# define MAGENTA        "\033[0;35m"
# define CYAN           "\033[0;36m"
# define RESET          "\033[0m"

# include <stdio.h>
# include <sys/time.h>
# include <unistd.h>

typedef struct s_philosopher
{
	int	eating_time;
	int	sleeping_time;
	int	thinking_time;
}	t_philosopher;

typedef struct s_coordinator
{
	int				nb_philosopher;
	int				global_eating_time;
	t_philosopher	*list;	
}	t_coordinator;

/* Main logic */
int	philosophers(void);

#endif
