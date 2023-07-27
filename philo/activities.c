/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   activities.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-moun <mel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 10:49:47 by mel-moun          #+#    #+#             */
/*   Updated: 2023/06/04 15:05:01 by mel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*activities(void *arg)
{
	t_philo	*all;

	all = (t_philo *)arg;
	if (all->id % 2 == 0)
	{
		print(all->global, all->id, "is thinking");
		my_usleep(all->global->t_eat, all->global);
	}
	pthread_mutex_lock(&all->global->mutex_death);
	while (all->global->death)
	{
		pthread_mutex_unlock(&all->global->mutex_death);
		print(all->global, all->id, "is thinking");
		taking_forks(all);
		eating(all);
		releasing_forks(all);
		sleeping(all);
		pthread_mutex_lock(&all->global->mutex_death);
	}
	pthread_mutex_unlock(&all->global->mutex_death);
	return (NULL);
}

void	releasing_forks(t_philo *all)
{
	pthread_mutex_unlock(&all->global->forks[all->id - 1]);
	pthread_mutex_unlock(&all->global->forks[all->id % all->global->num]);
}

void	eating(t_philo *all)
{
	print(all->global, all->id, "is eating");
	pthread_mutex_lock(&all->global->mutex_now);
	all->elapsed = current_time() - all->global->start_of_prog;
	pthread_mutex_unlock(&all->global->mutex_now);
	if (all->global->eat_p != -1)
	{
		pthread_mutex_lock(&all->global->num_eat_mutex);
		all->num_eat++;
		pthread_mutex_unlock(&all->global->num_eat_mutex);
		if (all->num_eat == all->global->eat_p)
		{
			pthread_mutex_lock(&all->global->mutex_total_meals);
			all->global->total_meals++;
			pthread_mutex_unlock(&all->global->mutex_total_meals);
		}
	}
	my_usleep(all->global->t_eat, all->global);
}
