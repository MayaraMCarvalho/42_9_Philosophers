/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macarval <macarval@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 15:37:31 by macarval          #+#    #+#             */
/*   Updated: 2023/11/24 08:33:55 by macarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	create_table(t_table *table, int argc, char *argv[])
{
	table->n_philos = ft_atoi(argv[1]);
	table->n_forks = table->n_philos;
	table->t_die = ft_atoi(argv[2]);
	table->t_eat = ft_atoi(argv[3]);
	table->t_sleep = ft_atoi(argv[4]);
	table->n_times = -1;
	if (argc == 6)
		table->n_times = ft_atoi(argv[5]);
	create_philo(table);
	table->watcher = (t_watch *) malloc (sizeof (t_watch));
	if (!table->watcher)
		return ;
	table->watcher->philo_died = 0;
	gettimeofday(&table->start, NULL);
}

void	create_philo(t_table *table)
{
	int		i;

	table->philos = (t_philo *) malloc (table->n_philos * sizeof (t_philo));
	if (!table->philos)
		return ;
	i = -1;
	while (++i < table->n_philos)
	{
		table->philos[i].id = i + 1;
		table->philos[i].hand_forks = 0;
		table->philos[i].t_die = table->t_die;
		table->philos[i].t_eat = table->t_eat;
		table->philos[i].t_sleep = table->t_sleep;
		table->philos[i].start = table->start;
	}
}
