/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macarval <macarval@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 11:53:42 by macarval          #+#    #+#             */
/*   Updated: 2023/11/30 11:37:28 by macarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	*action(void *arg)
{
	t_philo	*philo;
	t_table	*table;

	philo = (t_philo *) arg;
	table = philo->table;
	while (!read_mutex(&table->watcher->philo_died, &table->watcher->mutex)
		&& philo->n_times_eat != 0)
	{
		if (philo->id % 2 == 0)
			usleep(1000);
		eating(philo, table);
		sleeping(philo, table);
		thinking(philo, table);
		if (check_dead(philo, table))
			break ;
	}
	return (NULL);
}

void	eating(t_philo *philo, t_table *table)
{
	int	right_fork;
	int	left_fork;

	define_id_forks(philo, &right_fork, &left_fork);
	if (!check_dead(philo, table)
		&& !read_mutex(&table->watcher->philo_died, &table->watcher->mutex))
	{
		while (!take_forks(philo, table, right_fork, left_fork))
		{
			usleep(1);
			if (check_dead(philo, table))
				break ;
		}
		if (!check_dead(philo, table))
		{
			print_life(philo, MSG_EAT, 1);
			pthread_mutex_lock(&philo->mutex_eat);
			philo->n_times_eat--;
			pthread_mutex_unlock(&philo->mutex_eat);
			usleep(table->data->t_eat * 1000);
		}
		return_forks(table, right_fork, left_fork);
	}
}

void	sleeping(t_philo *philo, t_table *table)
{
	if (!read_mutex(&table->watcher->philo_died, &table->watcher->mutex))
	{
		print_life(philo, MSG_SLEEP, 0);
		usleep(table->data->t_sleep * 1000);
	}
	check_dead(philo, table);
}

void	thinking(t_philo *philo, t_table *table)
{
	if (!read_mutex(&table->watcher->philo_died, &table->watcher->mutex))
	{
		print_life(philo, MSG_THINK, 0);
		usleep(1000);
	}
}

void	print_life(t_philo *philo, char	*msg, int is_eat)
{
	struct timeval	end;
	long int		time;

	gettimeofday(&end, NULL);
	time = time_diff(&((t_table *)philo->table)->start, &end);
	pthread_mutex_lock(&((t_table *)philo->table)->mutex_print);
	printf("%li %i %s\n", time, philo->id, msg);
	pthread_mutex_unlock(&((t_table *)philo->table)->mutex_print);
	if (is_eat)
		philo->last_eat = time;
}
