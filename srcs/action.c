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
	printf("%d has taken a fork\n", philo->id);
	printf("%d has taken a fork\n", philo->id);
	printf("%d is eating\n", philo->id);
	usleep(philo->env->time_to_eat * 1000);
	philo->nb_meal_eaten += 1;
}

void	ft_sleeping(t_philo *philo)
{
	printf("%d is sleeping\n", philo->id);
	usleep(philo->env->time_to_sleep * 1000);
}

void	ft_thinking(t_philo *philo)
{
	printf("%d is thinking\n", philo->id);
}