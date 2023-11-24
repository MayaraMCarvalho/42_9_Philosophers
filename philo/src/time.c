/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macarval <macarval@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 09:16:10 by macarval          #+#    #+#             */
/*   Updated: 2023/11/23 10:04:34 by macarval         ###   ########.fr       */
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

void	*init(void *arg)
{
	int				j;
	t_philo			*philo;
	struct timeval	end;

	philo = (t_philo *)arg;
	j = 0;
	while (++j < 6)
	{
		gettimeofday(&end, NULL);
		action(time_diff(&philo->start, &end), philo, j);
	}
	return (NULL);
}
