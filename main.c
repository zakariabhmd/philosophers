/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbabahmi <zbabahmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 16:08:29 by zbabahmi          #+#    #+#             */
/*   Updated: 2023/10/03 23:44:20 by zbabahmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "philo.h"
int main(int ac, char **av)
{
	t_damage	*data;
	t_savage	*philo;

	if	(ac == 5 || ac == 6)
	{
		if (check_args(av))
			return (1);
		data = malloc(sizeof(t_damage));
		if(alloc_philo(data, &philo, av))
			return (printf("khataa fi alloc\n"), 1);
	}
	else
	{
		printf("khataa matba3i");
		return(1);
	}
	return(0);
}