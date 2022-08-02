/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_philos.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ywadday <ywadday@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 19:06:17 by ywadday           #+#    #+#             */
/*   Updated: 2022/08/02 23:13:49 by ywadday          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	create_philos(pthread_t	*threads, t_philo *philos, int size)
{
	// printf("%d", size);
	if (!(threads = (pthread_t *)malloc(sizeof(pthread_t) * size)))
		return (0);
	if (!(philos = (t_philo *)malloc(sizeof(t_philo) * size)))
		return (0);
	return (1);
}