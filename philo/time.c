/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-moun <mel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 17:32:39 by mel-moun          #+#    #+#             */
/*   Updated: 2023/06/04 15:20:49 by mel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	my_usleep(size_t time, t_args *all)
{
	size_t	t_sleep;
	size_t	now;

	t_sleep = current_time() + time;
	now = current_time();
	pthread_mutex_lock(&all->mutex_death);
	while (now < t_sleep && all->death)
	{
		pthread_mutex_unlock(&all->mutex_death);
		usleep(200);
		now = current_time();
		pthread_mutex_lock(&all->mutex_death);
	}
	pthread_mutex_unlock(&all->mutex_death);
}

size_t	current_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}
