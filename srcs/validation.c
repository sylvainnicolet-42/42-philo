/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: synicole <synicole@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 15:09:48 by synicole          #+#    #+#             */
/*   Updated: 2023/04/30 15:09:50 by synicole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

static int	ft_is_digit(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int	ft_integer_atoi(const char *str)
{
	unsigned long long int	nb;
	int						i;

	i = 0;
	nb = 0;
	while (str[i] && (str[i] >= '0' && str[i] <= '9'))
	{
		nb = nb * 10 + (str[i] - '0');
		i++;
	}
	if (nb > INT_MAX)
		return (-1);
	return ((int)nb);
}

int	ft_is_valid_input(int argc, char **argv)
{
	int	i;
	int	nb;

	i = 1;
	while (i < argc)
	{
		if (!ft_is_digit(argv[i]))
			return (ft_msg(MSG_INVALID_INPUT_DIGIT, argv[i], 0));
		nb = ft_integer_atoi(argv[i]);
		if (nb == -1)
			return (ft_msg(MSG_INVALID_INPUT_DIGIT, argv[i], 0));
		if (i == 1 && (nb <= 0 || nb > ft_integer_atoi(MAX_PHILOS)))
			return (ft_msg(MSG_INVALID_INPUT_PHILO, MAX_PHILOS, 0));
		i++;
	}
	return (1);
}
