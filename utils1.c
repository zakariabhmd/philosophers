/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbabahmi <zbabahmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 16:39:29 by zbabahmi          #+#    #+#             */
/*   Updated: 2023/10/04 16:57:48 by zbabahmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_usleep(long int s, t_savage *ar)
{
	long int	start;

	start = time_s();
	(void)ar;
	while (time_s() - start < s)
		usleep(50);
}

int	check_meals(t_savage *ar)
{
	pthread_mutex_lock(&ar->arg->data_race);
	ar->meals--;
	if (ar->meals == 0)
	{
		ar->arg->philo_count--;
		if (ar->arg->philo_count == 0)
		{
			pthread_mutex_unlock(&ar->arg->data_race);
			return (1);
		}
	}
	pthread_mutex_unlock(&ar->arg->data_race);
	return (0);
}

void	join_philo(t_savage *ar, t_damage *strick)
{
	int	i;

	i = 0;
	while(i < strick->num_philo)
	{
		pthread_join(ar[i].philo, NULL);
		i++;
	}
}

void	mutex_des(t_savage *ar, t_damage *strick)
{
	int	i;

	i = 0;
	while (i < ar->arg->num_philo)
	{
		pthread_mutex_destroy(ar[i].arg->fork);
		i++;
	}
	pthread_mutex_destroy(&ar->arg->print_mutex);
	free(ar->arg->fork);
	free (strick);
	free(ar);
}

int	dead(t_damage *strick, t_savage *ar, int i)
{
	pthread_mutex_lock(&(ar[i].arg->data_race));
	if (time_s() - ar[i].last_meal >= ar->arg->time_to_die
		&& ar->arg->flag == 0)
	{
		pthread_mutex_lock(&(ar[i].arg->print_mutex));
		printf("%ld %d %s\n", time_s() - ar->arg->time_start,
			ar->id, "died");
		ar->arg->flag = 1;
		pthread_mutex_unlock(&(ar[i].arg->print_mutex));
		pthread_mutex_unlock(&(ar[i].arg->data_race));
		join_philo(ar, strick);
		mutex_des(ar, strick);
		return (1);
	}
	return (0);
}
