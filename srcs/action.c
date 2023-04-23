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
	ft_print_action(philo, "has taken a fork");
	pthread_mutex_lock(philo->right_fork);
	ft_print_action(philo, "has taken a fork");
	ft_print_action(philo, "is eating");
	usleep(philo->env->time_to_eat * 1000);
	philo->nb_meal_eaten += 1;
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
}

void	ft_sleeping(t_philo *philo)
{
	ft_print_action(philo, "is sleeping");
	usleep(philo->env->time_to_sleep * 1000);
}

void	ft_thinking(t_philo *philo)
{
	ft_print_action(philo, "is thinking");
}

void	ft_die(t_philo *philo)
{
	ft_print_action(philo, "died");
	philo->is_dead = TRUE;
}
