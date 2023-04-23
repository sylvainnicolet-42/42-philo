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
# define DEBUG TRUE

typedef struct s_env
{
	int				nb_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				philo_must_eat;
	int				meal_must_be_checked;
	int				is_ready;
	int				is_over;
	long int		start_time;
	pthread_mutex_t	*fork;
}	t_env;

typedef struct s_philo
{
	int				id;
	int				nb_meal_eaten;
	int				is_dead;
	long int		thread_start_time;
	long int		last_meal_time;
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

// ----- SIMULATION ----- //
int			ft_start_simulation(t_env *env);

// ----- ACTIONS ----- //
void		ft_eating(t_philo *philo);
void		ft_sleeping(t_philo *philo);
void		ft_thinking(t_philo *philo);
void		ft_die(t_philo *philo);

// ----- UTILS ----- //
int			ft_atoi(const char *str);
long int	ft_now(void);

// ----- PRINT ----- //
void		ft_print_action(t_philo *philo, char *action);

// ----- DEBUG ----- //
void		ft_display_env(t_env *env);
void		ft_display_philos(t_philo *philo, t_env *env);

#endif