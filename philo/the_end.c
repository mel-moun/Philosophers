/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   the_end.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-moun <mel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 17:30:45 by mel-moun          #+#    #+#             */
/*   Updated: 2023/06/04 17:14:31 by mel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	free_all(t_args *all)
{
	int	i;

	i = 0;
	while (i < all->num)
	{
		pthread_mutex_destroy(&all->forks[i]);
		i++;
	}
	pthread_mutex_destroy(&all->mutex_death);
	pthread_mutex_destroy(&all->print);
	pthread_mutex_destroy(&all->mutex_total_meals);
	pthread_mutex_destroy(&all->mutex_now);
	pthread_mutex_destroy(&all->num_eat_mutex);
	free(all->philos);
	free(all);
}

void	join_threads(t_args *all)
{
	int	i;

	i = 0;
	while (i < all->num)
	{
		if (pthread_join(all->philos[i].philo, NULL) != 0)
			return ;
		i++;
	}
}

int	someone_died(t_args *all)
{
	int	now;
	int	i;

	i = 0;
	while (i < all->num)
	{
		pthread_mutex_lock(&all->mutex_now);
		now = current_time() - all->start_of_prog - all->philos[i].elapsed;
		pthread_mutex_unlock(&all->mutex_now);
		if (now >= all->t_die)
		{
			pthread_mutex_lock(&all->mutex_death);
			all->death = 0;
			pthread_mutex_unlock(&all->mutex_death);
			pthread_mutex_lock(&all->print);
			printf("%lu %d %s\n", current_time() - all->start_of_prog, \
			i + 1, "died");
			if (all->num == 1)
				pthread_mutex_unlock(&all->forks[0]);
			pthread_mutex_unlock(&all->print);
			return (1);
		}
		i++;
	}
	return (0);
}

int	meals_done(t_args *all, int ac)
{
	int	total_meals;

	if (ac != 6)
		return (0);
	pthread_mutex_lock(&all->mutex_total_meals);
	total_meals = all->total_meals;
	pthread_mutex_unlock(&all->mutex_total_meals);
	if (all->eat_p != -1 && total_meals == all->num)
	{
		pthread_mutex_lock(&all->mutex_death);
		all->death = 0;
		pthread_mutex_unlock(&all->mutex_death);
		return (1);
	}
	return (0);
}
