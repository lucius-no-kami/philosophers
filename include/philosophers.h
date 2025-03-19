/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luluzuri <luluzuri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 09:26:53 by luluzuri          #+#    #+#             */
/*   Updated: 2025/03/19 14:28:37 by luluzuri         ###   ########.fr       */
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
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>

# define MTX_ERROR		"mutex init as failed"
# define ENTRIES_ERROR	"entries must be greater than 0"
# define NUM_ERROR		"only numbers are accepted as input."
# define PHILO_ERROR	"number of philos must be contained between 1 and 200"
# define USAGE			"<philo_number> <time_to_die> <time_to_eat> \
<time_to_sleep> [time_each_philo_must_eat]\n"

typedef pthread_mutex_t	t_mtx;

typedef struct s_philo
{
	pthread_t		thread;
	int				id;
	int				eating;
	int				meals_eaten;
	size_t			last_meal;
	size_t			time_to_die;
	size_t			time_to_eat;
	size_t			time_to_sleep;
	size_t			start_time;
	int				num_of_philos;
	int				num_times_to_eat;
	int				*dead;
	t_mtx			*r_fork;
	t_mtx			*l_fork;
	t_mtx			*write_lock;
	t_mtx			*dead_lock;
	t_mtx			*meal_lock;
}					t_philo;

typedef struct s_program
{
	int				dead_flag;
	t_mtx			dead_lock;
	t_mtx			meal_lock;
	t_mtx			write_lock;
	t_philo			*philos;
}					t_program;

/* Init */
int		global_init(t_program *prog, t_philo *tab, \
					pthread_mutex_t *forks, char **entries);

/* Utils */
int		ft_atoi(const char *nptr);
void	clean(t_program *prog);

#endif
