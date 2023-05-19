/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: synicole <synicole@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 12:07:30 by synicole          #+#    #+#             */
/*   Updated: 2023/05/19 12:07:32 by synicole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

static void	ft_set_simulation_stop_flag(t_env *env, int is_over)
{
	pthread_mutex_lock(&env->simulation_stop_lock);
	env->is_over = is_over;
	pthread_mutex_unlock(&env->simulation_stop_lock);
}

static int	ft_kill_philo(t_philo *philo)
{
	time_t	time;

	time = ft_get_time_in_ms();
	if ((time - philo->last_meal) >= philo->env->time_to_die)
	{
		ft_set_simulation_stop_flag(philo->env, 1);
		ft_write_status(philo, 1, E_DIED);
		pthread_mutex_unlock(&philo->meal_time_lock);
		return (1);
	}
	return (0);
}

static int	ft_end_condition_reached(t_env *env)
{
	unsigned int	i;
	int				all_ate_enough;

	all_ate_enough = 1;
	i = 0;
	while (i < env->nb_philos)
	{
		pthread_mutex_lock(&env->philosophers[i]->meal_time_lock);
		if (ft_kill_philo(env->philosophers[i]))
			return (1);
		if (env->must_eat_count != -1)
			if (env->philosophers[i]->nb_meal_eaten
				< (unsigned int)env->must_eat_count)
				all_ate_enough = 0;
		pthread_mutex_unlock(&env->philosophers[i]->meal_time_lock);
		i++;
	}
	if (env->must_eat_count != -1 && all_ate_enough == 1)
	{
		ft_set_simulation_stop_flag(env, 1);
		return (1);
	}
	return (0);
}

void	*ft_monitoring(void *data)
{
	t_env	*env;

	env = (t_env *)data;
	if (env->must_eat_count == 0)
		return (NULL);
	ft_set_simulation_stop_flag(env, 0);
	ft_simulation_start_delay(env->start_time);
	while (1)
	{
		if (ft_end_condition_reached(env) == 1)
			return (NULL);
		usleep(1000);
	}
}
