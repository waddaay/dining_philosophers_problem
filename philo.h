/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ywadday <ywadday@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 18:17:17 by ywadday           #+#    #+#             */
/*   Updated: 2022/08/14 00:59:17 by ywadday          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_mutex{
	pthread_mutex_t	*mutex;
	long			current_time;
	int				finished;
	pthread_mutex_t	print;
}t_mutex;

typedef struct s_philo{
	int		id;
	int		n;
	int		time_to_die;
	int		time_to_eat;
	int		time_to_sleep;
	int		must_eat;
	t_mutex	*mtx;
	long	last_meal;
}t_philo;

int		init_philos(t_philo *philos, int ac, char **av, t_mutex *mutex);
int		ft_atoi(char *str);
int		create_philos(pthread_t	**threads, t_philo **philos,
			t_mutex **mutex, int size);
long	getime(void);
void	print(long time, t_philo philo, char *str);
void	ft_usleep(long time);
#endif
