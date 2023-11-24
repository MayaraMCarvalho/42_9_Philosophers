/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macarval <macarval@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 16:18:59 by macarval          #+#    #+#             */
/*   Updated: 2023/11/24 08:57:44 by macarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	manage_threads(t_table *table)
{
	pthread_t	observer;

	pthread_mutex_init(&table->watcher->mutex, NULL);
	table->threads = create_threads(table);
	if (!table->threads)
		return (1);
	if (pthread_create(&observer, NULL, observer_threads, &table) != 0)
		return (2);
	if (pthread_join(observer, NULL) != 0)
		return (3);
	join_threads(table);
	pthread_mutex_destroy(&table->watcher->mutex);
	free(table->threads);
	return (0);
}

pthread_t	*create_threads(t_table *table)
{
	int				i;
	int				j;
	pthread_t		*threads;

	j = table->n_times;
	threads = (pthread_t *) malloc (table->n_philos * sizeof(pthread_t));
	if (!threads)
		return (NULL);
	while (j != 0)
	{
		i = -1;
		while (++i < table->n_philos)
		{
			table->philos[i].watch = table->watcher;
			table->philos[i].start = table->start;
			if (pthread_create(&threads[i], NULL,
					&init, &table->philos[i]) != 0)
				return (NULL);
		}
		if (table->n_times > 0)
				j--;
	}
	return (threads);
}

int	join_threads(t_table *table)
{
	int	i;

	i = -1;
	while (++i < table->n_philos)
	{
		if (pthread_join(table->threads[i], NULL) != 0)
			return (i);
	}
	return (0);
}

void	*observer_threads(void *arg)
{
	t_table		*table;

	table = *(t_table **)arg;
	if(table) {}//
	// while (1)
	// {
	// 	pthread_mutex_lock(&table->watcher->mutex);
	// 	if (table->watcher->philo_died)
	// 	{
	// 		// join_threads(table);
	// 		// pthread_mutex_unlock(&table->watcher->mutex);
	// 		// free(table->philos);
	// 		// free(table->threads);
	// 		// free(table->watcher);
	// 		// exit (1);
	// 	}
	// 	pthread_mutex_unlock(&table->watcher->mutex);
	// 	usleep(10 * 1000);
	// }
	return (NULL);
}
