/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ywadday <ywadday@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 20:06:11 by ywadday           #+#    #+#             */
/*   Updated: 2022/08/14 00:47:42 by ywadday          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *arg)
{
	t_philo	*philo;
	long	current_time;

	philo = (t_philo *)arg;
	current_time = philo->mtx->current_time;
	philo->last_meal = getime();
	while (philo->must_eat != 0)
	{
		pthread_mutex_lock(&philo->mtx->mutex[philo->id]);
		print(getime() - current_time, *philo, "has taken a fork");
		pthread_mutex_lock(&philo->mtx->mutex[(philo->id + 1) % philo->n]);
		print(getime() - current_time, *philo, "has taken a fork");
		print(getime() - current_time, *philo, "is eating");
		ft_usleep(philo->time_to_eat * 1000);
		philo->last_meal = getime();
		pthread_mutex_unlock(&philo->mtx->mutex[philo->id]);
		pthread_mutex_unlock(&philo->mtx->mutex[(philo->id + 1) % philo->n]);
		print(getime() - current_time, *philo, "is sleeping");
		ft_usleep(philo->time_to_sleep * 1000);
		if (philo->must_eat != -1)
			philo->must_eat--;
	}
	if (philo->must_eat == 0)
		philo->mtx->finished++;
	return (NULL);
}

void	*check_death(t_philo *philos)
{
	int	i;

	while (1)
	{
		if (philos[0].mtx->finished == philos[0].n)
			return (NULL);
		i = -1;
		while (++i < philos[0].n)
		{
			if (getime() - philos[i].last_meal >= philos[0].time_to_die)
			{
				pthread_mutex_lock(&philos[i].mtx->print);
				printf("%ld %d die\n", getime() - philos[i].mtx->current_time,
					philos[i].id + 1);
				return (NULL);
			}
		}
	}
	return (NULL);
}

int	check_args(int ac)
{
	if (ac != 5 && ac != 6)
	{
		printf("Invalid Arguments");
		return (0);
	}
	return (1);
}

int	main(int ac, char *av[])
{
	pthread_t	*threads;
	t_philo		*philos;
	t_mutex		*mutex;
	int			i;

	if (!check_args(ac))
		return (0);
	if (!create_philos(&threads, &philos, &mutex, ft_atoi(av[1])))
		return (0);
	if (!init_philos(philos, ac, av, mutex))
		return (0);
	i = -1;
	pthread_mutex_init(&(mutex->print), NULL);
	mutex->current_time = getime();
	while (++i < philos[0].n)
	{
		if (pthread_create(&threads[i], NULL, &routine, &philos[i]) != 0)
			return (0);
		usleep(100);
	}
	check_death(philos);
	free(mutex);
	return (0);
}
