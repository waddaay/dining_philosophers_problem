/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ywadday <ywadday@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 18:43:22 by ywadday           #+#    #+#             */
/*   Updated: 2022/08/14 00:34:03 by ywadday          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_philos(t_philo *philos, int ac, char **av, t_mutex *mutex)
{
	int	size;
	int	i;

	size = ft_atoi(av[1]);
	i = -1;
	mutex->mutex = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * size);
	if (!mutex)
		return (0);
	mutex->finished = 0;
	while (++i < size)
	{
		philos[i].id = i;
		philos[i].n = ft_atoi(av[1]);
		philos[i].time_to_die = ft_atoi(av[2]);
		philos[i].time_to_eat = ft_atoi(av[3]);
		philos[i].time_to_sleep = ft_atoi(av[4]);
		pthread_mutex_init(&mutex->mutex[i], NULL);
		philos[i].mtx = mutex;
		if (ac == 6)
			philos[i].must_eat = ft_atoi(av[5]);
		else
			philos[i].must_eat = -1;
	}
	return (1);
}
