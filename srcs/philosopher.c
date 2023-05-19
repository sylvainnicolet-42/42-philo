/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: synicole <synicole@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 21:27:57 by synicole          #+#    #+#             */
/*   Updated: 2023/04/30 21:27:59 by synicole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

static void	ft_philo_sleep(t_env *env, time_t sleep_time)
{
	time_t	wake_up;

	wake_up = ft_get_time_in_ms() + sleep_time;
	while (ft_get_time_in_ms() < wake_up)
	{
		if (ft_is_simulation_over(env))
			break ;
		usleep(100);
	}
}

static void	ft_eat_sleep(t_philo *philo)
{
	pthread_mutex_lock(&philo->env->fork_locks[philo->fork[0]]);
	ft_write_status(philo, 0, E_GOT_FORK_1);
	pthread_mutex_lock(&philo->env->fork_locks[philo->fork[1]]);
	ft_write_status(philo, 0, E_GOT_FORK_2);
	ft_write_status(philo, 0, E_EATING);
	pthread_mutex_lock(&philo->meal_time_lock);
	philo->last_meal = ft_get_time_in_ms();
	pthread_mutex_unlock(&philo->meal_time_lock);
	ft_philo_sleep(philo->env, philo->env->time_to_eat);
	if (ft_is_simulation_over(philo->env) == 0)
	{
		pthread_mutex_lock(&philo->meal_time_lock);
		philo->nb_meal_eaten += 1;
		pthread_mutex_unlock(&philo->meal_time_lock);
	}
	ft_write_status(philo, 0, E_SLEEPING);
	pthread_mutex_unlock(&philo->env->fork_locks[philo->fork[1]]);
	pthread_mutex_unlock(&philo->env->fork_locks[philo->fork[0]]);
	ft_philo_sleep(philo->env, philo->env->time_to_sleep);
}

static void	ft_think(t_philo *philo, int silent)
{
	time_t	time_to_think;

	pthread_mutex_lock(&philo->meal_time_lock);
	time_to_think = (philo->env->time_to_die
			- (ft_get_time_in_ms() - philo->last_meal)
			- philo->env->time_to_eat) / 2;
	pthread_mutex_unlock(&philo->meal_time_lock);
	if (time_to_think < 0)
		time_to_think = 0;
	if (time_to_think == 0 && silent == 1)
		time_to_think = 1;
	if (time_to_think > 600)
		time_to_think = 200;
	if (silent == 0)
		ft_write_status(philo, 0, E_THINKING);
	ft_philo_sleep(philo->env, time_to_think);
}

static void	*ft_alone(t_philo *philo)
{
	pthread_mutex_lock(&philo->env->fork_locks[philo->fork[0]]);
	ft_write_status(philo, 0, E_GOT_FORK_1);
	ft_philo_sleep(philo->env, philo->env->time_to_die);
	ft_write_status(philo, 0, E_DIED);
	pthread_mutex_unlock(&philo->env->fork_locks[philo->fork[0]]);
	return (NULL);
}

void	*ft_philo_routine(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	if (philo->env->must_eat_count == 0)
		return (NULL);
	pthread_mutex_lock(&philo->meal_time_lock);
	philo->last_meal = philo->env->start_time;
	pthread_mutex_unlock(&philo->meal_time_lock);
	ft_simulation_start_delay(philo->env->start_time);
	if (philo->env->time_to_die == 0)
		return (NULL);
	if (philo->env->nb_philos == 1)
		return (ft_alone(philo));
	else if (philo->id % 2)
		ft_think(philo, 1);
	while (!ft_is_simulation_over(philo->env))
	{
		ft_eat_sleep(philo);
		ft_think(philo, 0);
	}
	return (NULL);
}
