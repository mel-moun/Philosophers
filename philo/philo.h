/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-moun <mel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 15:26:24 by mel-moun          #+#    #+#             */
/*   Updated: 2023/06/04 13:26:00 by mel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_philo	t_philo;

typedef struct s_args
{
	int				num;
	int				t_die;
	int				t_eat;
	int				t_sleep;
	int				eat_p;
	size_t			start_of_prog;
	int				death;
	int				total_meals;
	pthread_mutex_t	forks[200];
	pthread_mutex_t	print;
	pthread_mutex_t	mutex_death;
	pthread_mutex_t	mutex_total_meals;
	pthread_mutex_t	mutex_now;
	pthread_mutex_t	num_eat_mutex;
	t_philo			*philos;
}	t_args;

typedef struct s_philo
{
	int			elapsed;
	int			id;
	int			num_eat;
	t_args		*global;
	pthread_t	philo;
}	t_philo;

void	releasing_forks(t_philo *all);
void	eating(t_philo *all);
void	sleeping(t_philo *all);
void	the_end(t_args *all, int ac);
int		ft_atoi(char *s);
int		min_max(long num, int sign);
int		space_empty(char *s);
int		taking_arguments(char **av, t_args **all);
size_t	current_time(void);
int		initialize_mutexes(t_args *all);
int		initialize_philos(t_args **all);
int		creating_threads(t_args *all);
void	print(t_args *all, int id, char *s);
void	*activities(void *arg);
void	taking_forks(t_philo *all);
void	my_usleep(size_t to_sleep, t_args *all);
int		someone_died(t_args *all);
void	join_threads(t_args *all);
int		meals_done(t_args *all, int ac);
void	free_all(t_args *all);
#endif
