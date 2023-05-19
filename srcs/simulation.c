/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: synicole <synicole@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 11:34:52 by synicole          #+#    #+#             */
/*   Updated: 2023/04/30 11:34:53 by synicole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	ft_start_simulation(t_env *env)
{
	unsigned int	i;

	printf("start simulation\n");
	env->start_time = ft_get_time_in_ms() + (env->nb_philos * 2 * 10);
	i = 0;
	while (i < env->nb_philos)
	{
		if (pthread_create(&env->philosophers[i]->thread,
				NULL, &ft_philo_routine, env->philosophers[i]) != 0)
			return (ft_error_int(MSG_ERR_THREAD, env));
		i++;
	}
	if (env->nb_philos > 1)
	{
		if (pthread_create(&env->monitoring,
				NULL, &ft_monitoring, env) != 0)
			return (ft_error_int(MSG_ERR_THREAD, env));
	}
	return (1);
}

void	ft_stop_simulation(t_env *env)
{
	unsigned int	i;

	i = 0;
	while (i < env->nb_philos)
	{
		pthread_join(env->philosophers[i]->thread, NULL);
		i++;
	}
	if (env->nb_philos > 1)
		pthread_join(env->monitoring, NULL);
	if (DEBUG == 1 && env->must_eat_count != -1)
		ft_write_outcome(env);
	ft_destroy_mutexes(env);
	ft_free_env(env);
}

void	ft_simulation_start_delay(time_t start_time)
{
	while (ft_get_time_in_ms() < start_time)
		continue ;
}

int	ft_is_simulation_over(t_env *env)
{
	int	is_over;

	is_over = 0;
	pthread_mutex_lock(&env->simulation_stop_lock);
	if (env->is_over == 1)
		is_over = 1;
	pthread_mutex_unlock(&env->simulation_stop_lock);
	return (is_over);
}
