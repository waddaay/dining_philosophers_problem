/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ywadday <ywadday@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 18:50:18 by ywadday           #+#    #+#             */
/*   Updated: 2022/08/14 00:57:05 by ywadday          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(char *str)
{
	int	i;
	int	res;
	int	sign;

	i = 0;
	res = 0;
	sign = 1;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i++] == '-')
			sign = -1;
	}
	while (str[i])
		res = res * 10 + str[i++] - '0';
	return (res * sign);
}

long	getime(void)
{
	struct timeval	current_time;
	long			time;

	gettimeofday(&current_time, NULL);
	time = current_time.tv_sec * 1000 + current_time.tv_usec / 1000;
	return (time);
}

void	print(long time, t_philo philo, char *str)
{
	pthread_mutex_lock(&philo.mtx->print);
	printf("%ld %d %s\n", time, philo.id + 1, str);
	pthread_mutex_unlock(&philo.mtx->print);
}

void	ft_usleep(long time)
{
	long	start;

	start = getime();
	while (getime() - start < time / 1000)
		usleep(100);
}
