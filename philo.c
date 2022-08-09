/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ywadday <ywadday@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 20:06:11 by ywadday           #+#    #+#             */
/*   Updated: 2022/08/09 19:37:54 by ywadday          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void *routine(void *arg)
{
  t_philo *philo;
  long long     n;
  philo = (t_philo *)arg;

  n = -1;
  if (philo->number_of_times_each_philosopher_must_eat != 0)
    n = philo->number_of_times_each_philosopher_must_eat;
  while (n != 0)
  {
    if (philo->id % 2)
      usleep(500);
    pthread_mutex_lock(&philo->mtx->mutex[philo->id]);
    printf("philo %d take right fork\n", philo->id + 1);
    pthread_mutex_lock(&philo->mtx->mutex[(philo->id + 1) % philo->number_of_philosophers]);
    printf("philo %d take left fork\n", philo->id + 1);
    printf("philo %d eating \n", philo->id + 1);
    usleep(philo->time_to_eat * 1000);
    pthread_mutex_unlock(&philo->mtx->mutex[philo->id]);
    pthread_mutex_unlock(&philo->mtx->mutex[(philo->id + 1) % philo->number_of_philosophers]);
    if (n != -1)
      n--;
  }
  return NULL;
}

int main(int ac, char *av[])
{
    pthread_t   *threads;
    t_philo     *philos;
    int         i;
    t_mutex     mutex; 
    
    if (ac != 5 && ac != 6)
    {
        printf("Invalid Arguments");
        return (0);
    }
    if(!create_philos(&threads, &philos, ft_atoi(av[1])))
		return (0);
    if(!init_philos(philos, ac, av, &mutex))
      return (0);
    i = -1;
    while (++i < philos[0].number_of_philosophers)
    {
      if(pthread_create(&threads[i], NULL, &routine, &philos[i]) != 0)
        return (0);
      usleep(100000);
    }
    i = -1;
    while (++i < philos[0].number_of_philosophers)
    {
      if(pthread_join(threads[i], NULL) != 0)
        return (0);
    }
}