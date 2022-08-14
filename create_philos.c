/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_philos.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ywadday <ywadday@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 19:06:17 by ywadday           #+#    #+#             */
/*   Updated: 2022/08/14 00:48:58 by ywadday          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	create_philos(pthread_t **threads,
	t_philo **philos, t_mutex **mutex, int size)
{
	*mutex = (t_mutex *)malloc(sizeof(mutex));
	if (!mutex)
		return (0);
	*threads = (pthread_t *)malloc(sizeof(pthread_t) * size) + 1;
	if (!(*threads))
		return (0);
	*philos = (t_philo *)malloc(sizeof(t_philo) * size);
	if (!(*philos))
		return (0);
	return (1);
}
