/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-moun <mel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 10:50:17 by mel-moun          #+#    #+#             */
/*   Updated: 2023/06/04 16:27:00 by mel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	initialize_mutexes(t_args *all)
{
	int	i;

	i = 0;
	while (i < all->num)
	{
		if (pthread_mutex_init(&all->forks[i], NULL) != 0)
			return (1);
		i++;
	}
	if (pthread_mutex_init(&all->mutex_death, NULL) != 0)
		return (1);
	if (pthread_mutex_init(&all->print, NULL) != 0)
		return (1);
	if (pthread_mutex_init(&all->mutex_total_meals, NULL) != 0)
		return (1);
	if (pthread_mutex_init(&all->mutex_now, NULL) != 0)
		return (1);
	if (pthread_mutex_init(&all->num_eat_mutex, NULL) != 0)
		return (1);
	return (0);
}

int	initialize_philos(t_args **all)
{
	int	i;

	(*all)->philos = (t_philo *)malloc(sizeof(t_philo) * (*all)->num);
	if (!(*all)->philos)
		return (1);
	i = 0;
	while (i < (*all)->num)
	{
		(*all)->philos[i].id = i + 1;
		(*all)->philos[i].num_eat = 0;
		(*all)->philos[i].elapsed = 0;
		(*all)->philos[i].global = *all;
		i++;
	}
	return (0);
}

int	creating_threads(t_args *all)
{
	int	i;

	i = 0;
	while (i < all->num)
	{
		if (pthread_create(&all->philos[i].philo, NULL, &activities, \
		&all->philos[i]) != 0)
			return (1);
		i++;
	}
	return (0);
}
