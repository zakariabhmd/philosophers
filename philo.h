/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbabahmi <zbabahmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 15:57:51 by zbabahmi          #+#    #+#             */
/*   Updated: 2023/10/03 23:27:22 by zbabahmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

typedef struct s_damage{
	struct s_savage *philo;
	int	number_of_philo;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	number_of_time;
	pthread_mutex_t	*fork;
}t_damage;

typedef struct s_savage
{
	pthread_t thread;
	int		id;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
}	t_savage;

int		alloc_philo(t_damage *data, t_savage **philo, char **av);
int		check_args(char **av);
long	ft_atoi(char *str);

#endif