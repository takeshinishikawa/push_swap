/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_number.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtakeshi <rtakeshi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 15:10:01 by rtakeshi          #+#    #+#             */
/*   Updated: 2022/03/16 11:19:20 by rtakeshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static int	ft_isspace(int c)
{
	if (c == ' ' || c == '\n' || c == '\t' || c == '\r'
		|| c == '\f' || c == '\v')
		return (1);
	return (0);
}

int	check_number(const char *str)
{
	long int	num;
	int			signal;

	num = 0;
	signal = 1;
	while ((ft_isspace(*str)))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			signal *= -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		if (num * signal >= LONG_MAX / 10 && (*str - '0') > LONG_MAX % 10)
			return (0);
		else if (num * signal <= LONG_MIN / 10
			&& (*str - '0') > -(LONG_MIN % 10))
			return (0);
		num = (num * 10) + (*str - '0');
		str++;
	}
	return (1);
}
