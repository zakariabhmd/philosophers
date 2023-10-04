/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbabahmi <zbabahmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 15:57:51 by zbabahmi          #+#    #+#             */
/*   Updated: 2023/10/04 18:26:52 by zbabahmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <pthread.h>
# include <unistd.h>

typedef struct s_damage
{
	long			time_to_die;
	long			time_to_eat;
	long			time_to_sleep;
	long			num_philo;
	long			num_to_eat;
	pthread_mutex_t	*fork;
	pthread_mutex_t	print_mutex;
	pthread_mutex_t	data_race;
	long int		time_start;
	int				flag;
	int				philo_count;

}t_damage;

typedef struct s_savage
{
	long int	last_meal;
	t_damage	*arg;
	pthread_t	philo;
	int			meals;
	int			id;
	int			think;
	int			right_fork;
	int			left_fork;
	int			flag_r_fork;
	int			flag_l_fork;
}t_savage;

int			alloc_philo(char **av, t_damage *strick);
int			check_args(char **str);
long		ft_atoi(char *str);
int			int_max(char *ag);
void		init_forks(t_damage *strick);
void		ft_print(char *str, t_savage *ar);
void		ft_usleep(long int s, t_savage *ar);
long int	time_s(void);
int			check_meals(t_savage *ar);
int			dead(t_damage *strick, t_savage *ar, int i);
void		mutex_des(t_savage *ar, t_damage *strick);
void		join_philo(t_savage *ar, t_damage *strick);

#endif