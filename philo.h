/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ywadday <ywadday@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 18:17:17 by ywadday           #+#    #+#             */
/*   Updated: 2022/08/02 23:02:30 by ywadday          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
#include <pthread.h>

typedef struct s_philo{
    int id;
    int number_of_philosophers;
    int time_to_die;
    int time_to_eat;
    int time_to_sleep;
    int number_of_times_each_philosopher_must_eat;
}t_philo;

void    init_philos(t_philo *philos, int ac, char **av);
int     ft_atoi(char *str);
int     create_philos(pthread_t	*threads, t_philo *philos, int size);

#endif
