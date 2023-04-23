/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: synicole <synicole@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 17:27:30 by synicole          #+#    #+#             */
/*   Updated: 2023/04/23 17:27:32 by synicole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

/**
 * Returns the current timestamp in milliseconds.
 * This function uses gettimeofday to get the current time in microseconds.
 *
 * It calculates the current timestamp in milliseconds by multiplying
 * the number of seconds by 1000 and adding the number of microseconds
 * divided by 1000.
 *
 * @return The current timestamp in milliseconds.
*/
long int	ft_now(void)
{
	struct timeval	now;

	gettimeofday(&now, NULL);
	return ((now.tv_sec * 1000) + (now.tv_usec / 1000));
}
