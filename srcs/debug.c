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
	printf("\n----- ENV -----\n");
	printf("[nb_philo] => [%d]\n", env->nb_philo);
	printf("[time_to_die] => [%d]\n", env->time_to_die);
	printf("[time_to_eat] => [%d]\n", env->time_to_eat);
	printf("[time_to_sleep] => [%d]\n", env->time_to_sleep);
	printf("[philo_must_eat] => [%d]\n", env->philo_must_eat);
}

void	display_philo(t_philo *philo, t_env *env)
{
	int	i;

	printf("\n----- PHILOSOPHERS -----\n");
	i = 0;
	while (i < env->nb_philo + 1)
	{
		printf("[philo %d] => [id: %d]\n", i, philo[i].id);
		i++;
	}
}
