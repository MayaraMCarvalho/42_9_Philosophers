/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macarval <macarval@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 09:16:10 by macarval          #+#    #+#             */
/*   Updated: 2023/11/24 19:11:30 by macarval         ###   ########.fr       */
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

void	*init(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *) arg;
	action(philo);
	return (NULL);
}

void	action(t_philo *philo)
{
	int		i;
	t_table	*table;

	table = philo->table;
	i = table->data->n_times;
	while (i != 0)
	{
		eating(philo, table);
		sleeping(philo, table);
		thinking(philo, table);
		if (1) // tempo acabar
		{
			// printf("%li Philosopher %i is died\n", time, philo->id);
			// pthread_mutex_lock(&philo->watch->mutex);
			// philo->watch->philo_died = 1;
			// pthread_mutex_unlock(&philo->watch->mutex);
		}
		if (table->data->n_times > 0)
			i--;
	}
}
