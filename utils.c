/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbabahmi <zbabahmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 22:50:44 by zbabahmi          #+#    #+#             */
/*   Updated: 2023/10/04 18:29:32 by zbabahmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	ft_atoi(char *str)
{
	int	res;
	int	sign;
	int	i;

	res = 0;
	sign = 1;
	i = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	if (str[i] == '+')
		i++;
	while (str[i] && (str[i] >= '0' && str[i] <= '9'))
	{
		res = res * 10;
		res = res + str[i] - '0';
		i++;
	}
	return (sign * res);
}

int	int_max(char *ag)
{
	long	number;

	number = ft_atoi(ag);
	if (number > 2147483647 || number <= 0)
		return (1);
	return (0);
}

int	check_args(char **str)
{
	int	i;
	int	j;

	i = 1;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if (!(str[i][j] >= '0' && str[i][j] <= '9'))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

void	ft_print(char *str, t_savage *ar)
{
	pthread_mutex_lock(&(ar->arg->data_race));
	if (ar->arg->flag == 0)
	{
		pthread_mutex_lock(&ar->arg->print_mutex);
		printf("%ld %d %s\n", time_s() - ar->arg->time_start, ar->id, str);
		pthread_mutex_unlock(&ar->arg->print_mutex);
		pthread_mutex_unlock(&(ar->arg->data_race));
	}
	else
		pthread_mutex_unlock(&(ar->arg->data_race));
}
