/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macarval <macarval@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 09:16:10 by macarval          #+#    #+#             */
/*   Updated: 2023/11/27 00:30:42 by macarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

long int	time_diff(struct timeval *start, struct timeval *end)
{
	long int	time;

	time = (end->tv_sec - start->tv_sec) * 1e+3;
	time += (end->tv_usec - start->tv_usec) / 1e+3;
	return (time);
}

long int	get_now(struct timeval *start)
{
	struct timeval	end;
	long int		time;

	gettimeofday(&end, NULL);
	time = time_diff(start, &end);
	return (time);
}

void	*init(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *) arg;
	action(philo);
	return (NULL);
}

int	read_mutex(int	*var, pthread_mutex_t *mutex)
{
	int	res;

	pthread_mutex_lock(mutex);
	res = *var;
	pthread_mutex_unlock(mutex);
	return (res);
}

void	write_mutex(int *var, pthread_mutex_t *mutex, int value)
{
	pthread_mutex_lock(mutex);
	*var = value;
	pthread_mutex_unlock(mutex);
}
