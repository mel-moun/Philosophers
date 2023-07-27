/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-moun <mel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 10:50:02 by mel-moun          #+#    #+#             */
/*   Updated: 2023/06/04 17:14:08 by mel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_args	*all;

	if (ac != 5 && ac != 6)
		return (1);
	all = malloc(sizeof(t_args));
	if (!all)
		return (1);
	if (taking_arguments(av, &all))
	{
		printf("INVALID ARGUMENT\n");
		free(all);
		return (1);
	}
	if (initialize_mutexes(all) || initialize_philos(&all))
	{
		free(all->philos);
		free(all);
		return (1);
	}
	if (creating_threads(all))
	{
		free_all(all);
		return (1);
	}
	the_end(all, ac);
}

void	the_end(t_args *all, int ac)
{
	while (1)
	{
		if (someone_died(all) || meals_done(all, ac))
			break ;
	}
	join_threads(all);
	free_all(all);
}
