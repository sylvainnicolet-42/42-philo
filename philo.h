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
# include <limits.h>

// ----- DEBUG MODE ----- //
# ifndef DEBUG
#  define DEBUG 0
# endif

// ----- BOOLEAN ----- //
enum e_bool
{
	E_FALSE,
	E_TRUE,
};

// ----- MAX ----- //
# define MAX_PHILOS	"250"

// ----- MESSAGES ----- //
# define MSG_USAGE "Usage: ./philo <number_of_philosophers> \
<time_to_die> <time_to_eat> <time_to_sleep> \
[number_of_times_each_philosopher_must_eat]\n"
# define MSG_INVALID_INPUT_DIGIT "%s must be a valid integer between 0 \
and 2147483647.\n"
# define MSG_INVALID_INPUT_PHILO "Must be between 1 and %s philosophers.\n"
# define MSG_ERR_MALLOC	"Could not allocate memory.\n"
# define MSG_ERR_MUTEX	"Could not create mutex.\n"

// ----- STRUCTURES ----- //
typedef struct s_philo	t_philo;

typedef struct s_env
{
	unsigned int	nb_philos;
	time_t			time_to_die;
	time_t			time_to_eat;
	time_t			time_to_sleep;
	int				must_eat_count;
	int				is_over;
	t_philo			**philosophers;
}	t_env;

typedef struct s_philo
{
	unsigned int	id;
	unsigned int	nb_meal_eaten;
	unsigned int	fork[2];
	pthread_mutex_t	meal_time_lock;
	t_env			*env;
}	t_philo;

// ----- ENV ----- //
t_env	*ft_init_env(int argc, char **argv);

// ----- VALIDATION ----- //
int		ft_is_valid_input(int argc, char **argv);
int		ft_integer_atoi(const char *str);

// ----- SIMULATION ----- //
int		ft_start_simulation(t_env *env);
void	ft_stop_simulation(t_env *env);

// ----- TIME ----- //
time_t	ft_get_time_in_ms(void);

// ----- EXIT ----- //
int		ft_msg(char *str, char *detail, int exit_n);
void	*ft_error(char *str);

#endif