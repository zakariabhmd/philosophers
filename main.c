/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbabahmi <zbabahmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 16:08:29 by zbabahmi          #+#    #+#             */
/*   Updated: 2023/10/04 17:29:44 by zbabahmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	routine2(t_savage *ar, int first_time)
{
	pthread_mutex_unlock(&ar->arg->data_race);
	ft_print("is thinking", ar);
	if (ar->id % 2 == 0 && first_time)
		usleep(2000);
	pthread_mutex_lock(&ar->arg->fork[ar->right_fork]);
	ft_print("has taken a fork", ar);
	pthread_mutex_lock(&ar->arg->fork[ar->left_fork]);
	ft_print("has taken a fork", ar);
	pthread_mutex_lock(&ar->arg->data_race);
	ar->last_meal = time_s();
	pthread_mutex_unlock(&ar->arg->data_race);
	ft_print("is eating", ar);
	ft_usleep(ar->arg->time_to_eat, ar);
	pthread_mutex_unlock(&ar->arg->fork[ar->right_fork]);
	pthread_mutex_unlock(&ar->arg->fork[ar->left_fork]);
	ft_print("is sleeping", ar);
	ft_usleep(ar->arg->time_to_sleep, ar);
}

void	*routine(void *das)
{
	t_savage	*ar;
	int	first_time;

	ar = (t_savage *)das;
	first_time = 1;
	if (ar->arg->num_philo == 1)
	{
		ft_print("is thinking", ar);
		ft_print("has taken a fork", ar);
		return (NULL);
	}
	while (1)
	{
		pthread_mutex_lock(&ar->arg->data_race);
		if (ar->arg->philo_count == 0 || ar->arg->flag)
		{
			pthread_mutex_unlock(&ar->arg->data_race);
			break ;
		}
		routine2(ar, first_time);
		if (check_meals(ar))
			break ;
		first_time = 0;
	}
	return (NULL);
}

t_savage	*init_philo2(t_damage *strick)
{
	int	i;
	t_savage	*ar;

	ar = malloc(sizeof(t_savage) * strick->num_philo);
	strick->philo_count = strick->num_philo;
	i = 0;
	while (i < strick->num_philo)
	{
		ar[i].id = i + 1;
		ar[i].arg = strick;
		ar[i].right_fork = i;
		ar[i].left_fork = (i + 1) & ar->arg->num_philo;
		ar[i].last_meal = time_s();
		ar[i].meals = ar->arg->num_to_eat;
		pthread_create(&ar[i].philo, NULL, routine, &ar[i]);
		i++;
	}
	return (ar);
}

void	init_philo(t_damage *strick, int ac)
{
	int	i;
	t_savage	*ar;

	ar = init_philo2(strick);
	while (1)
	{
		i = -1;
		while(++i < strick->num_philo)
		{
			pthread_mutex_lock(&(ar[i].arg->data_race));
			if(strick->philo_count == 0 && ac == 6)
			{
				pthread_mutex_unlock(&(ar[i].arg->data_race));
				join_philo(ar, strick);
				mutex_des(ar, strick);
				return ;
			}
			pthread_mutex_unlock(&(ar[i].arg->data_race));
			if (dead(strick, ar, i))
				return ;
			pthread_mutex_unlock(&(ar[i].arg->data_race));
		}
	}
	join_philo(ar, strick);
	mutex_des(ar, strick);
}

int main(int ac, char **av)
{
	t_damage	*strick;

	if	(check_args(av) == 0 && (ac == 5 || ac == 6))
	{
		strick = malloc(sizeof(t_damage));
		if (alloc_philo(av, strick) == 1)
		{
			write (1, "invalide argument\n", 18);
			free (strick);
			return (0);
		}
		if (ac == 6)
		{
			strick->num_to_eat = ft_atoi(av[5]);
			if(strick->num_to_eat == 0)
				return(0);
		}
		strick->fork = malloc(sizeof(pthread_mutex_t) * strick->num_philo);
		init_forks(strick);
		strick->time_start = time_s();
		strick->flag = 0;
		init_philo(strick, ac);
	}
	else
		return(0);
}