/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_philos.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ywadday <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 19:06:17 by ywadday           #+#    #+#             */
/*   Updated: 2022/07/27 19:40:34 by ywadday          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_each_philo    *create_philos(in num)
{
    int     i;
    pthread_t *thread;
    t_each_philo *philos;

    i = 0;
    philos = (t_each_philo *)malloc(sizeof(t_each_philo) * num);
    while (i < num)
    {
        thread = (pthread_t *)malloc(sizeof(pthread_t *)); 
        philos[i]->id = i;
        philos[i]->fork = -1;
        philos[i++]->thread = thread;
    }
    return (philos);
}