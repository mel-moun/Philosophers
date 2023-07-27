/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-moun <mel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 15:32:31 by mel-moun          #+#    #+#             */
/*   Updated: 2023/05/30 17:33:03 by mel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	taking_arguments(char **av, t_args **all)
{
	if (space_empty(av[1]) || space_empty(av[2]) || space_empty(av[3]) \
	|| space_empty(av[4]))
		return (1);
	(*all)->num = ft_atoi(av[1]);
	(*all)->t_die = ft_atoi(av[2]);
	(*all)->t_eat = ft_atoi(av[3]);
	(*all)->t_sleep = ft_atoi(av[4]);
	(*all)->eat_p = -1;
	(*all)->total_meals = 0;
	(*all)->start_of_prog = current_time();
	(*all)->death = 1;
	if ((*all)->num <= 0 || (*all)->t_die <= 0 \
	|| (*all)->t_eat <= 0 || (*all)->t_sleep <= 0)
		return (1);
	if (av[5])
	{
		(*all)->eat_p = ft_atoi(av[5]);
		if ((*all)->eat_p <= 0 || space_empty(av[5]))
			return (1);
	}
	return (0);
}

int	space_empty(char *s)
{
	int	i;

	if (!*s)
		return (1);
	i = 0;
	while (s[i])
	{
		if (!(s[i] >= '0' || s[i] <= '9') || (s[i] == 32 && s[i] != '+'))
			return (1);
		i++;
	}
	return (0);
}

int	min_max(long num, int sign)
{
	if (num * sign > 2147483647 || num * sign < -2147483648)
		return (-1);
	return (0);
}

int	ft_atoi(char *s)
{
	int		i;
	long	num;
	int		sign;

	i = 0;
	num = 0;
	sign = 1;
	while (s[i] == 32 || (s[i] >= 9 && s[i] <= 13))
		i++;
	if (s[i] == '+' || s[i] == '-')
	{
		if (s[i] == '-')
			sign = sign * (-1);
		if (s[++i] == 0)
			return (-1);
	}
	while (s[i] >= '0' && s[i] <= '9')
	{
		num = num * 10 + s[i] - 48;
		i++;
	}
	if (s[i] != '\0' || min_max(num, sign) == -1)
		return (-1);
	return (sign * num);
}
