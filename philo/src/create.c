/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macarval <macarval@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 15:37:31 by macarval          #+#    #+#             */
/*   Updated: 2023/11/24 19:03:25 by macarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	create_data(t_table *table, int argc, char *argv[])
{
	table->data = (t_data *) malloc (sizeof (t_data));
	table->data->t_die = ft_atoi(argv[2]);
	table->data->t_eat = ft_atoi(argv[3]);
	table->data->t_sleep = ft_atoi(argv[4]);
	table->data->n_times = -1;
	if (argc == 6)
		table->data->n_times = ft_atoi(argv[5]);
}

void	create_table(t_table *table, int argc, char *argv[])
{
	table->n_philos = ft_atoi(argv[1]);
	create_data(table, argc, argv);
	create_philo(table);
	create_forks(table);
	table->watcher = (t_watch *) malloc (sizeof (t_watch));
	if (!table->watcher)
		return ;
	table->watcher->philo_died = 0;
	gettimeofday(&table->start, NULL);
}

void	create_forks(t_table *table)
{
	int	i;

	i = -1;
	table->forks = (t_fork *) malloc (table->n_philos * sizeof (t_fork));
	if (!table->forks)
		return ;
	while (++i < table->n_philos)
	{
		table->forks[i].id = i + 1;
		table->forks[i].avaliable = 1;
		pthread_mutex_init(&table->forks[i].mutex_fork, NULL);
	}
}

void	create_philo(t_table *table)
{
	int	i;

	table->philos = (t_philo *) malloc (table->n_philos * sizeof (t_philo));
	if (!table->philos)
		return ;
	i = -1;
	while (++i < table->n_philos)
	{
		table->philos[i].id = i + 1;
		table->philos[i].hand_forks = 0;
		table->philos[i].start = table->start;
		// table->philos[i].last_eat = ;
	}
}
