/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_philos.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ywadday <ywadday@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 19:06:17 by ywadday           #+#    #+#             */
/*   Updated: 2022/08/09 18:39:55 by ywadday          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	create_philos(pthread_t	**threads, t_philo **philos, int size)
{
	int i;
	
	if (!(*threads = (pthread_t *)malloc(sizeof(pthread_t) * size)))
		return (0);
	if (!(*philos = (t_philo *)malloc(sizeof(t_philo) * size)))
		return (0);
	return (1);
}

