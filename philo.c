/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ywadday <ywadday@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 20:06:11 by ywadday           #+#    #+#             */
/*   Updated: 2022/08/02 23:03:23 by ywadday          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int main(int ac, char *av[])
{
    pthread_t   *threads;
    t_philo     *philos;

    if (ac != 5 && ac != 6)
    {
        printf("Invalid Arguments");
        return (0);
    }
    if(!create_philos(threads, philos, ft_atoi(av[1])))
        return (0);
    init_philos(philos, ac, av);
    printf("%d", philos[0].id);
}