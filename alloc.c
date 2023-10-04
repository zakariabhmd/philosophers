/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbabahmi <zbabahmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 23:04:25 by zbabahmi          #+#    #+#             */
/*   Updated: 2023/10/04 18:37:37 by zbabahmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long int	time_s(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

int	alloc_philo(char **av, t_damage *strick)
{
	int	i;

	strick->num_philo = ft_atoi(av[1]);
	strick->time_to_die = ft_atoi(av[2]);
	strick->time_to_eat = ft_atoi(av[3]);
	strick->time_to_sleep = ft_atoi(av[4]);
	i = 1;
	while (i <= 4)
	{
		if (int_max(av[i]) == 1)
			return (1);
		i++;
	}
	return (0);
}

void	init_forks(t_damage *strick)
{
	int	i;

	i = 0;
	while (i < strick->num_philo)
	{
		pthread_mutex_init(&strick->fork[i], NULL);
		i++;
	}
	pthread_mutex_init(&strick->print_mutex, NULL);
	pthread_mutex_init(&strick->data_race, NULL);
}
