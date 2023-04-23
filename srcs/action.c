/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: synicole <synicole@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 22:40:07 by synicole          #+#    #+#             */
/*   Updated: 2023/04/20 22:40:09 by synicole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	ft_eating(t_philo *philo)
{
	pthread_mutex_lock(philo->left_fork);
	printf("%ld %d has taken a fork\n", ft_now(), philo->id);
	pthread_mutex_lock(philo->right_fork);
	printf("%ld %d has taken a fork\n", ft_now(), philo->id);
	printf("%ld %d is eating\n", ft_now(), philo->id);
	usleep(philo->env->time_to_eat * 1000);
	philo->nb_meal_eaten += 1;
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
}

void	ft_sleeping(t_philo *philo)
{
	printf("%ld %d is sleeping\n", ft_now(), philo->id);
	usleep(philo->env->time_to_sleep * 1000);
}

void	ft_thinking(t_philo *philo)
{
	printf("%d is thinking\n", philo->id);
}
