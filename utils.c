/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbabahmi <zbabahmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 22:50:44 by zbabahmi          #+#    #+#             */
/*   Updated: 2023/10/03 23:02:06 by zbabahmi         ###   ########.fr       */
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
	if(number > 2147483647 || number <= 0)
		return (1);
	return (0);
}

int	inv_num(char *ag)
{
	int	i;
	int	flg;

	i = 0;
	flg = 0;
	while(ag[i])
	{
		if (ag[i] == '+' || ag[i] == '-')
		{
			if (i > 0 || flg == 1)
				return(1);
			flg = 1;
		}
		else if (!(ag[i] >= '0' && ag[i] <= '9'))
			return (1);
		i++;
	}
	if (flg == 1 && i == 1)
		return (1);
	return (0);
}

int	check_args(char **av)
{
	int	i;

	i = 1;
	while(av[1])
	{
		if (int_max(av[1]) || inv_num(av[i]))
		{
			printf("khataa");
			return (1);
		}
		i++;
	}
	return (0);
}