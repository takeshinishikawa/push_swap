/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validations.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtakeshi <rtakeshi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 17:12:19 by rtakeshi          #+#    #+#             */
/*   Updated: 2022/03/19 20:26:01 by rtakeshi         ###   ########.fr       */
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
		return (1);
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

int	is_sorted(t_sentinel *data)
{
	t_node	*curr;

	curr = data->head_a;
	while (curr != data->tail_a)
	{
		if (curr->index != curr->next->index - 1)
			return (1);
		curr = curr->next;
	}
	return (0);
}

int	is_repeated(t_sentinel *data)
{
	t_node	*curr;
	t_node	*needle;

	curr = data->head_a;
	while (curr)
	{
		needle = curr->next;
		while (needle)
		{
			if (curr->nbr == needle->nbr)
				return (1);
			if (needle->next == curr)
				break ;
			needle = needle->next;
		}
		if (curr->next == data->head_a)
			break ;
		curr = curr->next;
	}
	return (0);
}
