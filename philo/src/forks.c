/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macarval <macarval@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 15:41:50 by macarval          #+#    #+#             */
/*   Updated: 2023/11/26 16:18:53 by macarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	take_forks(t_philo *philo, t_table *table)
{
	int	right_fork;
	int	left_fork;

	right_fork = philo->id - 1;
	left_fork = philo->id - 2;
	if (philo->id == 1)
		left_fork = table->n_philos - 1;
	pthread_mutex_lock(&table->forks[right_fork].mutex_fork);
	if (table->forks[right_fork].avaliable)
	{
		table->forks[right_fork].avaliable = 0;
		has_fork(philo);
		pthread_mutex_lock(&table->forks[left_fork].mutex_fork);
		if (table->forks[left_fork].avaliable)
		{
			table->forks[left_fork].avaliable = 0;
			has_fork(philo);
		}
		else
		{
			pthread_mutex_unlock(&table->forks[left_fork].mutex_fork);
			return_forks(philo, table, right_fork);
		}
	}
}

void	has_fork(t_philo *philo)
{
	struct timeval	end;

	philo->hand_forks++;
	gettimeofday(&end, NULL);
	// printf("%li %i has a taken a fork\n",
	// 	time_diff(&philo->start, &end), philo->id);
}

void	return_forks(t_philo *philo, t_table *table, int id_fork)
{
	philo->hand_forks--;
	table->forks[id_fork].avaliable = 1;
	pthread_mutex_unlock(&table->forks[id_fork].mutex_fork);
}
