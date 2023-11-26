/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macarval <macarval@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 11:53:42 by macarval          #+#    #+#             */
/*   Updated: 2023/11/26 16:17:48 by macarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	eating(t_philo *philo, t_table *table)
{
	struct timeval	end;

	take_forks(philo, table);
	if (philo->hand_forks == 2)
	{
		gettimeofday(&end, NULL);
		printf("%li %i is eating\n", time_diff(&philo->start, &end), philo->id);
		usleep(table->data->t_eat * 1000);
		return_forks(philo, table, philo->id - 1);
		if (philo->id == 1)
			return_forks(philo, table, table->n_philos - 1);
		else
			return_forks(philo, table, philo->id - 2);
	}
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
