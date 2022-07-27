/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_philos.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ywadday <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 19:06:17 by ywadday           #+#    #+#             */
/*   Updated: 2022/07/27 22:56:10 by ywadday          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_each_philo	*create_philos(int num)
{
	int				i;
	t_each_philo	*philos;
	
	i = 0;
	philos = (t_each_philo *)malloc(sizeof(t_each_philo) * num);
	while (i < num)
	{
		philos[i].id = i + 1;
		philos[i].fork = 0;
		philos[i++].thread = (pthread_t *)malloc(sizeof(pthread_t *)); 
	}
	return (philos);
}