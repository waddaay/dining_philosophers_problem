/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ywadday <ywadday@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 18:43:22 by ywadday           #+#    #+#             */
/*   Updated: 2022/08/02 23:14:56 by ywadday          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void init_philos(t_philo *philos, int ac, char **av)
{
	int size;
	int i;
	
	size = ft_atoi(av[1]);
	i = -1;
	while(++i < size)
	{
		philos->id = i + 1;
		philos->number_of_philosophers = ft_atoi(av[1]);
		philos->time_to_die = ft_atoi(av[2]);
		philos->time_to_eat = ft_atoi(av[3]);
		philos->time_to_sleep = ft_atoi(av[4]);
		if (ac == 6)
			philos->number_of_times_each_philosopher_must_eat = ft_atoi(av[5]);
	}
}
