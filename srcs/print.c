/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: synicole <synicole@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 16:09:01 by synicole          #+#    #+#             */
/*   Updated: 2023/04/23 16:09:03 by synicole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	ft_print_action(t_philo *philo, char *action)
{
	printf(
		"[%ldms] => [philo %d] [%s] [nb_meal_eaten: %d]\n",
		ft_now() - philo->env->start_time, philo->id, action,
		philo->nb_meal_eaten);
}
