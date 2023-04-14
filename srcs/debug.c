/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: synicole <synicole@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 20:55:36 by synicole          #+#    #+#             */
/*   Updated: 2023/04/14 20:55:38 by synicole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	display_env(t_env *env)
{
	printf("----- ENV -----\n");
	printf("[nb_philo] => [%d]\n", env->nb_philo);
	printf("[time_to_die] => [%d]\n", env->time_to_die);
	printf("[time_to_eat] => [%d]\n", env->time_to_eat);
	printf("[time_to_sleep] => [%d]\n", env->time_to_sleep);
	printf("[philo_must_eat] => [%d]\n", env->philo_must_eat);
}
