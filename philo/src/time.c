/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macarval <macarval@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 09:16:10 by macarval          #+#    #+#             */
/*   Updated: 2023/11/09 18:17:46 by macarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

float	time_diff(struct timeval *start, struct timeval *end)
{
	float	sec;
	float	usec;
	float	time;

	sec = end->tv_sec - start->tv_sec;
	usec = end->tv_usec - start->tv_usec;
	time = sec * 1e+3 + usec / 1e+3;
	return (time);
}

void	*init_timer(void* arg)
{
	struct timeval	end;
	t_philo 	*philo;

	philo = (t_philo *)arg;
	int i = -1, j = 0;
	while (++j < 6)
	{
		while (++i < philo->t_die * 1000)
			;
		gettimeofday(&end, NULL);
		action(time_diff(&philo->start, &end), philo->id, j);
	}
	return (NULL);
}
