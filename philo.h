/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: synicole <synicole@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 19:43:07 by synicole          #+#    #+#             */
/*   Updated: 2023/04/14 19:43:09 by synicole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>

# define TRUE 1
# define FALSE 0

typedef struct s_env
{
	int			nb_philo;
	int			time_to_die;
	int			time_to_eat;
	int			time_to_sleep;
	int			philo_must_eat;
	long int	start_time;
}	t_env;

typedef struct s_philo
{
	int				id;
	int				nb_meal_eaten;
	int				is_dead;
	pthread_t		thread;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	t_env			*env;
}	t_philo;

// ----- ENV ----- //
int			ft_init_env(char **argv, t_env *env);

// ----- PHILOSOPHERS ----- //
int			ft_init_philos(t_philo *philo, t_env *env);
void		*ft_philo_life(void *arg);

// ----- THREADS ----- //
int			ft_init_threads(t_philo *philo, t_env *env);
void		ft_end_threads(t_philo *philo, t_env *env);

// ----- ACTIONS ----- //
void		ft_eating(t_philo *philo);
void		ft_sleeping(t_philo *philo);
void		ft_thinking(t_philo *philo);

// ----- UTILS ----- //
int			ft_atoi(const char *str);
long int	ft_now(void);

// ----- DEBUG ----- //
void		ft_display_env(t_env *env);
void		ft_display_philos(t_philo *philo, t_env *env);

#endif