/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validations.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtakeshi <rtakeshi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 17:12:19 by rtakeshi          #+#    #+#             */
/*   Updated: 2022/03/16 17:13:28 by rtakeshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

/**
 * @brief checks the number of arguments
 *
 * @param argc 1 -> no numbers informed and if 1 already sorted
 * @return int 1 if error and 0 if more than 2 possible numbers informed
 */
int	check_argc(int argc)
{
	if (argc == 1)
	{
		ft_putstr_fd("Error\n", 1);
		//ft_printf("Error\n");
		return (1);
	}
	else if (argc == 2)
		return (1);
	return (0);
}

int	check_argv(char	*argv)
{
	if (*argv == '+' || *argv == '-')
	{
		if (ft_isdigit(*(argv + 1)))
			return (1);
		else
			return (0);
	}
	else if (ft_isdigit(*argv))
		return (1);
	return (0);
}
