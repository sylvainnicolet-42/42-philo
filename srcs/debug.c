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

void	ft_display_env(t_env *env)
{
	printf("\n----- ENV -----\n");
	printf("[nb_philo] => [%d]\n", env->nb_philo);
	printf("[time_to_die] => [%d]\n", env->time_to_die);
	printf("[time_to_eat] => [%d]\n", env->time_to_eat);
	printf("[time_to_sleep] => [%d]\n", env->time_to_sleep);
	printf("[meal_must_be_checked] => [%d]\n", env->meal_must_be_checked);
	if (env->meal_must_be_checked == TRUE)
		printf(" ↳ [philo_must_eat] => [%d]\n", env->philo_must_eat);
	printf("[start_time] => [%ld]\n", env->start_time);
	printf("\n");
}

void	ft_display_philos(t_philo *philo, t_env *env)
{
	int	i;

	printf("\n----- PHILOSOPHERS -----\n");
	i = 0;
	while (i < env->nb_philo)
	{
		printf("[philo %d] => [id: %d] ", i, philo[i].id);
		printf("[nb_meal_eaten: %d] ", philo[i].nb_meal_eaten);
		printf("[is_dead: %d]\n", philo[i].is_dead);
		i++;
	}
}
