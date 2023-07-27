/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   activities_suppot.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-moun <mel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 17:36:57 by mel-moun          #+#    #+#             */
/*   Updated: 2023/05/30 17:39:02 by mel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print(t_args *all, int id, char *s)
{
	pthread_mutex_lock(&all->mutex_death);
	pthread_mutex_lock(&all->print);
	if (all->death)
		printf("%lu %d %s\n", current_time() - all->start_of_prog, id, s);
	pthread_mutex_unlock(&all->mutex_death);
	pthread_mutex_unlock(&all->print);
}

void	taking_forks(t_philo *all)
{
	int	left_fork;
	int	right_fork;

	left_fork = all->id - 1;
	right_fork = all->id % all->global->num;
	pthread_mutex_lock(&all->global->forks[left_fork]);
	print(all->global, all->id, "has taken a fork");
	pthread_mutex_lock(&all->global->forks[right_fork]);
	print(all->global, all->id, "has taken a fork");
}

void	sleeping(t_philo *all)
{
	print(all->global, all->id, "is sleeping");
	my_usleep(all->global->t_sleep, all->global);
}
