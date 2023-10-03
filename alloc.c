/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbabahmi <zbabahmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 23:04:25 by zbabahmi          #+#    #+#             */
/*   Updated: 2023/10/03 23:42:47 by zbabahmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	alloc_philo(t_damage *data, t_savage **philo, char **av)
{
	t_savage	*philoso;

	data->number_of_philo = ft_atoi(av[1]);
	data->time_to_die = ft_atoi(av[2]);
	data->time_to_eat = ft_atoi(av[3]);
	data->time_to_die = ft_atoi(av[4]);
	if(av[5])
		data->number_of_time = ft_atoi(av[5]);
	else
		data->number_of_time = -1;
	data->fork = malloc(sizeof(pthread_mutex_t) * data->number_of_philo);
	if (!data->fork)
		return (1);
	philoso = malloc(sizeof(t_savage) * data->number_of_philo);
	if (!philoso)
	{
		free (data->fork);
		data->fork = NULL;
		return (1);
	}
	*philo = philoso;
	return(0);
}