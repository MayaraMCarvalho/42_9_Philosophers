/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macarval <macarval@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 11:53:42 by macarval          #+#    #+#             */
/*   Updated: 2023/11/24 08:40:18 by macarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	action(float time, t_philo *philo, int action)
{
	// if (action == TAKEN)
	// {
	// 	// Se o momento for comer, esperar para pegar garfo
	// 	printf("%0.f %i has a taken a fork\n", time, philo->id);
	// }
	if (action == EAT)
		eating(time, philo);
	else if (action == SLEEP)
		sleeping(time, philo);
	else if (action == THINK)
		thinking(time, philo);
	else if (action == DIED)
	{
		printf("%0.f Philosopher %i is died\n", time, philo->id);
		// pthread_mutex_lock(&philo->watch->mutex);
		// philo->watch->philo_died = 1;
		// pthread_mutex_unlock(&philo->watch->mutex);
	}
}

int	eating(float time, t_philo *philo)
{
	printf("%0.f %i is eating\n", time, philo->id);
	usleep(philo->t_eat * 1000);
	return (0);
}

int	sleeping(float time, t_philo *philo)
{
	printf("%0.f %i is sleeping\n", time, philo->id);
	usleep(philo->t_sleep * 1000);
	return (0);
}

int	thinking(float time, t_philo *philo)
{
	printf("%0.f %i is thinking\n", time, philo->id);
	// Ficar aqui até conseguir um garfo para comer take_fork()
	usleep(philo->t_eat * 1000); // Substitui por while(take_fork)
	return (0);
}
