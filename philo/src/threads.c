/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macarval <macarval@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 16:18:59 by macarval          #+#    #+#             */
/*   Updated: 2023/11/27 00:51:05 by macarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	manage_threads(t_table *table)
{
	pthread_t	observer;

	table->threads = create_threads(table);
	if (!table->threads)
		return (1);
	if (pthread_create(&observer, NULL, observer_threads, &table) != 0)
		return (2);
	if (pthread_join(observer, NULL) != 0)
		return (3);
	join_threads(table);
	return (0);
}

pthread_t	*create_threads(t_table *table)
{
	int			i;
	pthread_t	*threads;

	gettimeofday(&table->start, NULL);
	threads = (pthread_t *) malloc (table->n_philos * sizeof(pthread_t));
	if (!threads)
		return (NULL);
	i = -1;
	while (++i < table->n_philos)
	{
		table->philos[i].table = table;
		pthread_create(&threads[i], NULL, &init, &table->philos[i]);
	}
	return (threads);
}

int	join_threads(t_table *table)
{
	int	i;

	i = -1;
	while (++i < table->n_philos)
		pthread_join(table->threads[i], NULL);
	free(table->threads);
	return (0);
}

void	*observer_threads(void *arg)
{
	t_table		*table;

	table = *(t_table **)arg;
	while (1)
	{
		if (read_mutex(&table->watcher->philo_died, &table->watcher->mutex))
		{
			print_life(&table->philos[table->watcher->philo_died - 1],
				"died", 0);
			return ((void *) 1);
		}
		usleep(10 * 1000);
		if (final_eat(table))
			return (NULL);
	}
	return (NULL);
}

int	final_eat(t_table *table)
{
	int	i;

	i = -1;
	while (++i < table->n_philos)
	{
		if (table->philos[i].n_times_eat)
			return (0);
	}
	return (1);
}
