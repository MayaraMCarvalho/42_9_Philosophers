/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macarval <macarval@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 11:53:42 by macarval          #+#    #+#             */
/*   Updated: 2023/11/24 19:09:37 by macarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

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

int	eating(t_philo *philo, t_table *table)
{
	struct timeval	end;

	// while (philo->hand_forks != 2)
	// 	take_forks();
	// printf("%li %i has a taken a fork\n", time, philo->id);
	gettimeofday(&end, NULL);
	printf("%li %i is eating\n", time_diff(&philo->start, &end), philo->id);
	usleep(table->data->t_eat * 1000);
	//devolver garfos
	return (0);
}

int	sleeping(t_philo *philo, t_table *table)
{
	struct timeval	end;

	gettimeofday(&end, NULL);
	printf("%li %i is sleeping\n", time_diff(&philo->start, &end), philo->id);
	usleep(table->data->t_sleep * 1000);
	return (0);
}

int	thinking(t_philo *philo, t_table *table)
{
	struct timeval	end;

	gettimeofday(&end, NULL);
	printf("%li %i is thinking\n", time_diff(&philo->start, &end), philo->id);
	// Ficar aqui até conseguir um garfo para comer take_fork()
	usleep(table->data->t_eat * 1000); // Substitui por while(take_fork)
	return (0);
}
