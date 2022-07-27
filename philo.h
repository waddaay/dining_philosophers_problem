/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ywadday <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 18:17:17 by ywadday           #+#    #+#             */
/*   Updated: 2022/07/27 19:40:54 by ywadday          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
#include <pthread.h>

typedef struct s_philo{
    int number_of_philosophers;
    int time_to_die;
    int time_to_eat;
    int time_to_sleep;
    int number_of_times_each_philosopher_must_eat;
}t_philo;

typedef struct s_each_philo{
	int			id;
	int			fork;
	pthread_t	thread;
}t_each_philo;

void			init_philo(t_philo *philo);
int				ft_atoi(char *str);
t_each_philo    *create_philos(in num);

#endif
