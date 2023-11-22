/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macarval <macarval@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 11:53:42 by macarval          #+#    #+#             */
/*   Updated: 2023/11/09 18:41:04 by macarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	action(float time, int philo, int action)
{
	if (action == TAKEN)
		printf("%0.f %i has a taken a fork\n", time, philo);
	else if (action == EAT)
		printf("%0.f %i is eating\n",  time, philo);
	else if (action == SLEEP)
		printf("%0.f %i is sleeping\n",  time, philo);
	else if (action == THINK)
		printf("%0.f %i is thinking\n",  time, philo);
	else if (action == DIED)
	{
		printf("%0.f %i died\n",  time, philo);
		return (-1);
	}
	return (1);
}







